#include "core/Arduino.h"
#include "libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.h"
#include "libraries/Wire/src/Wire.h"
#include "libraries/SPI/src/SPI.h"
#include "libraries/Ethernet/src/Ethernet.h"
#include "libraries/Ethernet/src/EthernetUdp.h"
#include "libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.h"
#include "libraries/mpu6050/src/I2Cdev.h"
#include "libraries/mpu6050/src/MPU6050.h"

#include "FreeRTOS/Arduino_FreeRTOS.h"
#include "FreeRTOS/timers.h"

//tasks periods
#define T1 10 //cada 10 milis es canvia la rotacio del motor.
#define T2 20 //No s'usa
#define T3 10 // cada 10 milis hi ha el PID.
#define T4 10 // Cada 10 millis es pren la mostra.
#define MAX_VEL 250
#define MIN_VEL 65 //a velocitat menor s'encalla.

//Coses
// 1. Puc fer servir una llibreria pel PID?  --> Solucionat
// 2. Puc fer servir aqui la funcio millis() o necessito una crida especifica de freeRTOS? --> millis sembla funcionar correctament.
// 3. Poder cal afinar una miqueta mes lencoder --> FET.
// 4. No funciona el setup del wire. --> Cap problema.

MPU6050 MPU6050_sensor;
int16_t datax, datay, dataz;

//Direcci� del motor
int dir;
float consigna_posicio;
float encoderPosCount;
float posicio;
int gass;

//PID
	float kp, ki, kd; //PID constants.
	unsigned long currentTime, previousTime;
	float elapsedTime;
	float error;
	float lastError;
	float cumError, rateError;



// function prototypes
void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );
void Task4( void *pvParameters );
//void OneShotTimerCallback( TimerHandle_t xTimer );  //Debug
//void CanviaDirCallback( TimerHandle_t xTimer );

//Task handlers
TaskHandle_t Task1Handle;
TaskHandle_t TaskHandleEncoder;
TaskHandle_t Task3Handle;
TaskHandle_t Task4Handle;


//timer handlers
TimerHandle_t xPeriodicTimer, xOneShotTimer;
BaseType_t xPeriodicTimerStarted, xOneShotStarted;

//circular buffer for debugging
#define BUFF_SIZE 250
float t[BUFF_SIZE] = {};
char circ_buffer1[BUFF_SIZE] = {};
char circ_buffer2[BUFF_SIZE] = {};
char circ_buffer3[BUFF_SIZE] = {};
char circ_buffer4[BUFF_SIZE] = {};
char circ_buffer5[BUFF_SIZE] = {};
char circ_buffer6[BUFF_SIZE] = {};
float debug_data1[BUFF_SIZE] = {};

unsigned int circ_buffer_counter = 0;

float str_getTime(void)
{
  float t=(float)(0.5e-3*((float)OCR1A*xTaskGetTickCount()+TCNT1));//Sent time in milliseconds!!!
  return t;
}

//str_trace is a hook by the RTOS kernel used after a context-switch-in
void str_trace(void)
{
  circ_buffer_counter++;
  if (circ_buffer_counter >= BUFF_SIZE)
  {
    circ_buffer_counter = 0;
  }

  t[circ_buffer_counter] = str_getTime();//sent time in milliseconds
  circ_buffer1[circ_buffer_counter] = eTaskGetState(Task1Handle);
  circ_buffer2[circ_buffer_counter] = eTaskGetState(TaskHandleEncoder);
  circ_buffer3[circ_buffer_counter] = eTaskGetState(Task3Handle);
  circ_buffer4[circ_buffer_counter] = eTaskGetState(Task4Handle);
  circ_buffer5[circ_buffer_counter] = 0;
  circ_buffer6[circ_buffer_counter] = 0;
  debug_data1[circ_buffer_counter] = 1.1;

}

//str_compute(x) is only used to waste time without using delays
void str_compute(unsigned long milliseconds)
{
  unsigned int i = 0;
  unsigned int imax = 0;
  imax = milliseconds * 92;
  volatile float dummy = 1;
  for (i = 0; i < imax; i++)
  {
    dummy = dummy * dummy;
  }
}

void RSI_encoder(){
	//Serial.println(digitalRead(18));
	BaseType_t taskYieldRequired = 0;
	taskYieldRequired = xTaskResumeFromISR(TaskHandleEncoder);
	//Serial.println("DBG");
	if(taskYieldRequired == 1)
	    {
	        taskYIELD();
	    }
}

int computePID(float inp, float consigna){
	currentTime = millis();                //get current time
	elapsedTime = (float)(currentTime - previousTime);        //compute time elapsed from previous computation

	error = consigna - inp;                                // determine error
	cumError += error * elapsedTime;                // compute integral
	rateError = (error - lastError)/elapsedTime;   // compute derivative

	float out = kp*error + ki*cumError + kd*rateError;                //PID output

	lastError = error;                                //remember current error
	previousTime = currentTime;                        //remember current time

	//D'aquesta manera podem tenir el valor 0 a la velocitat.
	if 		(out > MAX_VEL) out = MAX_VEL;
	else if (out < -MAX_VEL) out = -MAX_VEL;
	else if (out > 0 && out < MIN_VEL) out = MIN_VEL;
	else if (out < 0 && out > -MIN_VEL) out = -MIN_VEL;
//	Serial.println (inp);
//	Serial.println(consigna);
//	Serial.println((int)out);
//	Serial.println((int)elapsedTime);
//	Serial.println("");
	return (int) out;                                        //have function return the PID output
}



void setup() {

    pinMode(LED_BUILTIN,OUTPUT);

    Serial.begin(115200);

	//xOneShotTimer = xTimerCreate("OneShotTimer", 50  , pdFALSE, 0, OneShotTimerCallback );
    //xOneShotTimer = xTimerCreate("OneShotTimer", 500  , pdFALSE, 0, CanviaDirCallback );
	xOneShotStarted = xTimerStart( xOneShotTimer, 0 );

	xTaskCreate(Task1," Task1", 192, NULL, 1, &Task1Handle); //velocitat i sentit de gir del motor. del motor. Prioritat mes baixa
	xTaskCreate(Task2, "Task2", 192, NULL, 4, &TaskHandleEncoder);//Handle de la interrupt. Prioritat mes alta --> Server.
	xTaskCreate(Task3, "Task3", 512, NULL, 2, &Task3Handle);//calcul ID
	xTaskCreate(Task4, "Task4", 512, NULL, 3, &Task4Handle);//Presa de la mostra del sensor.

	//Ordre d'importancia de tes tasks:
	//1. Interrupcio: Per tenir un server
	//2. Prendre la mostra
	//3. Calcular la direccio i velocitat del motor (PID)
	//4. Moure el motor amb la velocitat i direccio desitjades

	attachInterrupt(digitalPinToInterrupt(18), RSI_encoder, CHANGE);
	attachInterrupt(digitalPinToInterrupt(19), RSI_encoder, CHANGE);

	//variables
	dir = 1;
	consigna_posicio = 0;
	posicio = 0;
	gass = 0;

	kp = 50.0;
	ki = 0.001;
	kd = 0.01;
	previousTime = 0;
	elapsedTime = 0;
	error = 0;
	lastError = 0;
	cumError = 0;
	rateError = 0;

	//Pins
	pinMode (3,OUTPUT);
	pinMode (18,INPUT);
	pinMode (19,INPUT);
	pinMode (12,OUTPUT);

	//Sensor
//	Wire.begin(); // NO FUNCIONA.
	MPU6050_sensor.initialize();


}

void Task1(void *pvParameters)  // This is a task.
{
	(void) pvParameters;

	TickType_t xLastWakeTime;
	xLastWakeTime = 0;//xTaskGetTickCount();

	for (;;) // A Task shall never return or exit.
	{
		//Serial.println ("TASK1");
		//canvi de la direccio si toca
		if (gass < 0){
			dir = 0; // toca restar graus
			gass = -gass;
		}
		else dir = 1; //toca sumar graus

		//rectificacio de la posicio del motor.
		digitalWrite(12,dir);
		analogWrite(3,gass);    //gass

		//Serial.println("DEBuGGGG");
		vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(T1));
	}
}

void Task2(void *pvParameters)  // Handler de la interrupt. Calcula els graus.
{
	    (void) pvParameters;
		TickType_t xLastWakeTime;

		xLastWakeTime = 0;//5//xTaskGetTickCount();//a simple method to implement an offset at the beginning of the activation (current time should be greater than this value)


		for (;;)
		{
			// Serial.println("TASK2");
			 if (dir) //We're Rotating Clockwise
					 {
					  // Serial.println ("Rotate Clockwise");
					   encoderPosCount ++;
					   if (encoderPosCount >= 1440) encoderPosCount = 0; //360graus*4polsos/grau.
					 }

					 else

					 {
					   //Serial.println("Rotate Counterclockwise");
					   encoderPosCount--;
					   if (encoderPosCount <= -1440) encoderPosCount = 0;
					 }
			 posicio = encoderPosCount/4;  //calcul efectiu de la posicio.
			 vTaskSuspend(NULL);
		}
}

void Task3(void *pvParameters)  // PID
{
	(void) pvParameters;
	TickType_t xLastWakeTime;
	xLastWakeTime = 0;//xTaskGetTickCount();

	for (;;)
	{
		//Serial.println ("TASK3");
//		Serial.println (posicio);
//		Serial.println(consigna_posicio);
//		Serial.println((int)gass);
//		Serial.println("");
		gass = computePID(posicio,consigna_posicio);
		vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(T3));
	}

}

void Task4(void *pvParameters)  // Canvi de consigna_posicio
{
	(void) pvParameters;
	TickType_t xLastWakeTime;
	xLastWakeTime = 0;//xTaskGetTickCount();

	for (;;)
	{
	  //Serial.println ("TASK4");
//	  //Serial.println("canvi");
//	  if (consigna_posicio >= 90) consigna_posicio = -90;
//	  else consigna_posicio = 90;
	  MPU6050_sensor.getAcceleration(&datax, &datay, &dataz);
	  float pitch = atan2((float)-datax , sqrt((float)datay * (float)datay + (float)dataz * (float)dataz)) * 180.0 / PI;
	  consigna_posicio = pitch;
	  Serial.println((int)pitch);
	  vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(T4));
	}
}


// Per debug.
void OneShotTimerCallback( TimerHandle_t xTimer )
{
	TickType_t xTimeNow;
	xTimeNow = xTaskGetTickCount();

	//stop the RTOS kernel and send data
	//stop the kernel...
	vTaskSuspend(Task1Handle);
	vTaskSuspend(TaskHandleEncoder);
	vTaskSuspend(Task3Handle);
	vTaskSuspend(Task4Handle);
	vTaskSuspendAll();
	str_trace();
	//...and sent data to the host PC
	unsigned int i;
	for (i = 0; i < BUFF_SIZE; i++)
	{
		Serial.print((float)t[i]);
		Serial.write((uint8_t)circ_buffer1[i]);
		Serial.write((uint8_t)circ_buffer2[i]);
		Serial.write((uint8_t)circ_buffer3[i]);
		Serial.write((uint8_t)circ_buffer4[i]);
		Serial.write((uint8_t)circ_buffer5[i]);
		Serial.write((uint8_t)circ_buffer6[i]);
		Serial.print((float)debug_data1[i]);
		Serial.println();
	}
}

//void CanviaDirCallback( TimerHandle_t xTimer ){
//	TickType_t xTimeNow;
//	xTimeNow = xTaskGetTickCount();
//	dir = !dir;
//}

void loop()
{
    //Nothing to do in background
}

