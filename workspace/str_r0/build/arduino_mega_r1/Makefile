ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/FreeRTOS/croutine.cpp.o \
	project/FreeRTOS/event_groups.cpp.o \
	project/FreeRTOS/heap_3.cpp.o \
	project/FreeRTOS/list.cpp.o \
	project/FreeRTOS/port.cpp.o \
	project/FreeRTOS/queue.cpp.o \
	project/FreeRTOS/stream_buffer.cpp.o \
	project/FreeRTOS/tasks.cpp.o \
	project/FreeRTOS/timers.cpp.o \
	project/FreeRTOS/variantHooks.cpp.o \
	project/core/CDC.cpp.o \
	project/core/HardwareSerial.cpp.o \
	project/core/HardwareSerial0.cpp.o \
	project/core/HardwareSerial1.cpp.o \
	project/core/HardwareSerial2.cpp.o \
	project/core/HardwareSerial3.cpp.o \
	project/core/IPAddress.cpp.o \
	project/core/PluggableUSB.cpp.o \
	project/core/Print.cpp.o \
	project/core/Stream.cpp.o \
	project/core/Tone.cpp.o \
	project/core/USBCore.cpp.o \
	project/core/WMath.cpp.o \
	project/core/WString.cpp.o \
	project/core/abi.cpp.o \
	project/core/main.cpp.o \
	project/core/new.cpp.o \
	project/libraries/Ethernet/src/Dhcp.cpp.o \
	project/libraries/Ethernet/src/Dns.cpp.o \
	project/libraries/Ethernet/src/Ethernet.cpp.o \
	project/libraries/Ethernet/src/EthernetClient.cpp.o \
	project/libraries/Ethernet/src/EthernetServer.cpp.o \
	project/libraries/Ethernet/src/EthernetUdp.cpp.o \
	project/libraries/Ethernet/src/socket.cpp.o \
	project/libraries/Ethernet/src/utility/w5100.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_calibration.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_core.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_ranging.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_strings.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_i2c_comms.cpp.o \
	project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_platform.cpp.o \
	project/libraries/SPI/src/SPI.cpp.o \
	project/libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.cpp.o \
	project/libraries/Wire/src/Wire.cpp.o \
	project/libraries/mpu6050/src/I2Cdev.cpp.o \
	project/libraries/mpu6050/src/MPU6050.cpp.o \
	project/str_r0.cpp.o \

PLATFORM_CORE_OBJS = \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \

TARGETS = \
	str_r0.hex \

all: $(TARGETS)

str_r0.hex: str_r0.elf
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-objcopy" -O ihex -R .eeprom  "./str_r0.elf" "./str_r0.hex"

str_r0.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega2560   -o "./str_r0.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS)  "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "./str_r0.elf"

project/FreeRTOS/croutine.cpp.o: ../../FreeRTOS/croutine.cpp project/FreeRTOS/croutine.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/croutine.cpp.d: ;

-include project/FreeRTOS/croutine.cpp.d 

project/FreeRTOS/event_groups.cpp.o: ../../FreeRTOS/event_groups.cpp project/FreeRTOS/event_groups.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/event_groups.cpp.d: ;

-include project/FreeRTOS/event_groups.cpp.d 

project/FreeRTOS/heap_3.cpp.o: ../../FreeRTOS/heap_3.cpp project/FreeRTOS/heap_3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/heap_3.cpp.d: ;

-include project/FreeRTOS/heap_3.cpp.d 

project/FreeRTOS/list.cpp.o: ../../FreeRTOS/list.cpp project/FreeRTOS/list.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/list.cpp.d: ;

-include project/FreeRTOS/list.cpp.d 

project/FreeRTOS/port.cpp.o: ../../FreeRTOS/port.cpp project/FreeRTOS/port.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/port.cpp.d: ;

-include project/FreeRTOS/port.cpp.d 

project/FreeRTOS/queue.cpp.o: ../../FreeRTOS/queue.cpp project/FreeRTOS/queue.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/queue.cpp.d: ;

-include project/FreeRTOS/queue.cpp.d 

project/FreeRTOS/stream_buffer.cpp.o: ../../FreeRTOS/stream_buffer.cpp project/FreeRTOS/stream_buffer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/stream_buffer.cpp.d: ;

-include project/FreeRTOS/stream_buffer.cpp.d 

project/FreeRTOS/tasks.cpp.o: ../../FreeRTOS/tasks.cpp project/FreeRTOS/tasks.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/tasks.cpp.d: ;

-include project/FreeRTOS/tasks.cpp.d 

project/FreeRTOS/timers.cpp.o: ../../FreeRTOS/timers.cpp project/FreeRTOS/timers.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/timers.cpp.d: ;

-include project/FreeRTOS/timers.cpp.d 

project/FreeRTOS/variantHooks.cpp.o: ../../FreeRTOS/variantHooks.cpp project/FreeRTOS/variantHooks.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/FreeRTOS/variantHooks.cpp.d: ;

-include project/FreeRTOS/variantHooks.cpp.d 

project/core/CDC.cpp.o: ../../core/CDC.cpp project/core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/CDC.cpp.d: ;

-include project/core/CDC.cpp.d 

project/core/HardwareSerial.cpp.o: ../../core/HardwareSerial.cpp project/core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/HardwareSerial.cpp.d: ;

-include project/core/HardwareSerial.cpp.d 

project/core/HardwareSerial0.cpp.o: ../../core/HardwareSerial0.cpp project/core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/HardwareSerial0.cpp.d: ;

-include project/core/HardwareSerial0.cpp.d 

project/core/HardwareSerial1.cpp.o: ../../core/HardwareSerial1.cpp project/core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/HardwareSerial1.cpp.d: ;

-include project/core/HardwareSerial1.cpp.d 

project/core/HardwareSerial2.cpp.o: ../../core/HardwareSerial2.cpp project/core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/HardwareSerial2.cpp.d: ;

-include project/core/HardwareSerial2.cpp.d 

project/core/HardwareSerial3.cpp.o: ../../core/HardwareSerial3.cpp project/core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/HardwareSerial3.cpp.d: ;

-include project/core/HardwareSerial3.cpp.d 

project/core/IPAddress.cpp.o: ../../core/IPAddress.cpp project/core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/IPAddress.cpp.d: ;

-include project/core/IPAddress.cpp.d 

project/core/PluggableUSB.cpp.o: ../../core/PluggableUSB.cpp project/core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/PluggableUSB.cpp.d: ;

-include project/core/PluggableUSB.cpp.d 

project/core/Print.cpp.o: ../../core/Print.cpp project/core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/Print.cpp.d: ;

-include project/core/Print.cpp.d 

project/core/Stream.cpp.o: ../../core/Stream.cpp project/core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/Stream.cpp.d: ;

-include project/core/Stream.cpp.d 

project/core/Tone.cpp.o: ../../core/Tone.cpp project/core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/Tone.cpp.d: ;

-include project/core/Tone.cpp.d 

project/core/USBCore.cpp.o: ../../core/USBCore.cpp project/core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/USBCore.cpp.d: ;

-include project/core/USBCore.cpp.d 

project/core/WMath.cpp.o: ../../core/WMath.cpp project/core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/WMath.cpp.d: ;

-include project/core/WMath.cpp.d 

project/core/WString.cpp.o: ../../core/WString.cpp project/core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/WString.cpp.d: ;

-include project/core/WString.cpp.d 

project/core/abi.cpp.o: ../../core/abi.cpp project/core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/abi.cpp.d: ;

-include project/core/abi.cpp.d 

project/core/main.cpp.o: ../../core/main.cpp project/core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/main.cpp.d: ;

-include project/core/main.cpp.d 

project/core/new.cpp.o: ../../core/new.cpp project/core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/core/new.cpp.d: ;

-include project/core/new.cpp.d 

project/libraries/Ethernet/src/Dhcp.cpp.o: ../../libraries/Ethernet/src/Dhcp.cpp project/libraries/Ethernet/src/Dhcp.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/Dhcp.cpp.d: ;

-include project/libraries/Ethernet/src/Dhcp.cpp.d 

project/libraries/Ethernet/src/Dns.cpp.o: ../../libraries/Ethernet/src/Dns.cpp project/libraries/Ethernet/src/Dns.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/Dns.cpp.d: ;

-include project/libraries/Ethernet/src/Dns.cpp.d 

project/libraries/Ethernet/src/Ethernet.cpp.o: ../../libraries/Ethernet/src/Ethernet.cpp project/libraries/Ethernet/src/Ethernet.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/Ethernet.cpp.d: ;

-include project/libraries/Ethernet/src/Ethernet.cpp.d 

project/libraries/Ethernet/src/EthernetClient.cpp.o: ../../libraries/Ethernet/src/EthernetClient.cpp project/libraries/Ethernet/src/EthernetClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/EthernetClient.cpp.d: ;

-include project/libraries/Ethernet/src/EthernetClient.cpp.d 

project/libraries/Ethernet/src/EthernetServer.cpp.o: ../../libraries/Ethernet/src/EthernetServer.cpp project/libraries/Ethernet/src/EthernetServer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/EthernetServer.cpp.d: ;

-include project/libraries/Ethernet/src/EthernetServer.cpp.d 

project/libraries/Ethernet/src/EthernetUdp.cpp.o: ../../libraries/Ethernet/src/EthernetUdp.cpp project/libraries/Ethernet/src/EthernetUdp.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/EthernetUdp.cpp.d: ;

-include project/libraries/Ethernet/src/EthernetUdp.cpp.d 

project/libraries/Ethernet/src/socket.cpp.o: ../../libraries/Ethernet/src/socket.cpp project/libraries/Ethernet/src/socket.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/socket.cpp.d: ;

-include project/libraries/Ethernet/src/socket.cpp.d 

project/libraries/Ethernet/src/utility/w5100.cpp.o: ../../libraries/Ethernet/src/utility/w5100.cpp project/libraries/Ethernet/src/utility/w5100.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Ethernet/src/utility/w5100.cpp.d: ;

-include project/libraries/Ethernet/src/utility/w5100.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/Seeed_vl53l0x.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_calibration.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_calibration.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_calibration.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_calibration.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_calibration.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_core.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_core.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_core.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_core.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_core.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_ranging.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_ranging.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_ranging.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_ranging.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_ranging.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_strings.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_strings.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_strings.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_strings.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/core/src/vl53l0x_api_strings.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_i2c_comms.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_i2c_comms.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_i2c_comms.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_i2c_comms.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_i2c_comms.cpp.d 

project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_platform.cpp.o: ../../libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_platform.cpp project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_platform.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_platform.cpp.d: ;

-include project/libraries/Grove-Ranging-sensor-VL53L0X/src/platform/src/vl53l0x_platform.cpp.d 

project/libraries/SPI/src/SPI.cpp.o: ../../libraries/SPI/src/SPI.cpp project/libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/SPI/src/SPI.cpp.d: ;

-include project/libraries/SPI/src/SPI.cpp.d 

project/libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.cpp.o: ../../libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.cpp project/libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.cpp.d: ;

-include project/libraries/SparkFun_LSM6DS3_Breakout/src/SparkFunLSM6DS3.cpp.d 

project/libraries/Wire/src/Wire.cpp.o: ../../libraries/Wire/src/Wire.cpp project/libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/Wire/src/Wire.cpp.d: ;

-include project/libraries/Wire/src/Wire.cpp.d 

project/libraries/mpu6050/src/I2Cdev.cpp.o: ../../libraries/mpu6050/src/I2Cdev.cpp project/libraries/mpu6050/src/I2Cdev.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/mpu6050/src/I2Cdev.cpp.d: ;

-include project/libraries/mpu6050/src/I2Cdev.cpp.d 

project/libraries/mpu6050/src/MPU6050.cpp.o: ../../libraries/mpu6050/src/MPU6050.cpp project/libraries/mpu6050/src/MPU6050.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/libraries/mpu6050/src/MPU6050.cpp.d: ;

-include project/libraries/mpu6050/src/MPU6050.cpp.d 

project/str_r0.cpp.o: ../../str_r0.cpp project/str_r0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"C:\str\eclipse_arduino\eclipse\eclipse_arduino_home/packages/arduino/hardware/avr/1.8.3/variants/mega" "$<" -o "$@"

project/str_r0.cpp.d: ;

-include project/str_r0.cpp.d 




