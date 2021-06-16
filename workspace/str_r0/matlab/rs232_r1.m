clear all;
clc;
delete(instrfind);

BUFF_SIZE=250;

s=serial('COM6', 'BaudRate', 115200,'Terminator','LF','TimeOut',20);
fopen(s);

data=[];
t=[];
try
    for i=1:1:BUFF_SIZE
        data(i,:) = fscanf(s,'%f%c%c%c%c%c%c%f')';

        if(mod(i,50)==0)
            disp(['adquired ' num2str(i) ' samples']);
        end
    end
    t=data(:,1)/1e3;%time sent in milliseconds and converted to seconds
    t(t==0)=NaN;
    circ_buffer1=data(:,2);
    circ_buffer2=data(:,3);
    circ_buffer3=data(:,4);
    circ_buffer4=data(:,5);
    circ_buffer5=data(:,6);
    circ_buffer6=data(:,7);
    debug_data1=data(:,8);
    fclose(s);

    [min_t,pos_min_t]=min(t);
    t=           circshift(t,           -pos_min_t+1);
    circ_buffer1=circshift(circ_buffer1,-pos_min_t+1);
    circ_buffer2=circshift(circ_buffer2,-pos_min_t+1);
    circ_buffer3=circshift(circ_buffer3,-pos_min_t+1);
    circ_buffer4=circshift(circ_buffer4,-pos_min_t+1);
    circ_buffer5=circshift(circ_buffer5,-pos_min_t+1);
    circ_buffer6=circshift(circ_buffer6,-pos_min_t+1);
    
catch Me
    Me.identifier
    close all;
    disp("Error. Closing serial port...");
    fclose(s);
    return;
end


% Ready	eReady
% Running	eRunning (the calling task is querying its own priority)
% Blocked	eBlocked
% Suspended	eSuspended
% Deleted	eDeleted (the tasks TCB is waiting to be cleaned up)
% /* Task states returned by eTaskGetState. */
% typedef enum
% {
%     eRunning = 0,   /* A task is querying the state of itself, so must be running. */
%     eReady,         /* The task being queried is in a read or pending ready list. */
%     eBlocked,       /* The task being queried is in the Blocked state. */
%     eSuspended,     /* The task being queried is in the Suspended state, or is in the Blocked state with an infinite time out. */
%     eDeleted,       /* The task being queried has been deleted, but its TCB has not yet been freed. */
%     eInvalid        /* Used as an 'invalid state' value. */
% } eTaskState;

eRunning=0;
eReady=1;
eBlocked=2;
eSuspended=3;
eDeleted=4;
eInvalid=5;

circ_buffer1=subs(circ_buffer1,{eRunning,eReady,eBlocked,eSuspended},[2 1 0 2.5]);
circ_buffer2=subs(circ_buffer2,{eRunning,eReady,eBlocked,eSuspended},[2 1 0 2.5]);
circ_buffer3=subs(circ_buffer3,{eRunning,eReady,eBlocked,eSuspended},[2 1 0 2.5]);
circ_buffer4=subs(circ_buffer4,{eRunning,eReady,eBlocked,eSuspended},[2 1 0 2.5]);
circ_buffer5=subs(circ_buffer5,{eRunning,eReady,eBlocked,eSuspended},[2 1 0 2.5]);
circ_buffer6=subs(circ_buffer6,{eRunning,eReady,eBlocked,eSuspended},[2 1 0 2.5]);

close all;
figure;
hold on;
grid on;
box on;
stairs(t,circ_buffer1+0);
stairs(t,circ_buffer2+5);
stairs(t,circ_buffer3+10);
stairs(t,circ_buffer4+15);
stairs(t,circ_buffer5+20);
stairs(t,circ_buffer6+25);

% set(gca,'XTick',[0:0.100:max(t)]);
set(gca,'YTick',[0 1 2 2.5  5 6 7 7.5  10 11 12 12.5  15 16 17 17.5  20 21 22 22.5  25 26 27 27.5]);
set(gca,'YTickLabel',{'Ready','Blocked','Running','Suspended','Ready','Blocked','Running','Suspended','Ready','Blocked','Running','Suspended','Ready','Blocked','Running','Suspended','Ready','Blocked','Running','Suspended','Ready','Blocked','Running','Suspended'});
set(gca,'XMinorTick','on');



%plot arrival and deadlines

T1=10;
D1=10;
c1=2;

T2=20;
D2=15;
c2=4;

T3=30;
D3=25;
c3=6;

T4=100;
D4=90;
c4=15;

U=c1/T1+c2/T2+c3/T3+c4/T4;

a1_vector=0:T1/1000:max(t);
D1_vector=a1_vector+D1/1000;
plot([a1_vector; a1_vector], [0*5+0+zeros(1,length(a1_vector)); 0*5+3+zeros(1,length(a1_vector))],'Color',[1 .6 .6]);
plot([a1_vector], [0*5+3+zeros(1,length(a1_vector))],'^','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);
plot([D1_vector; D1_vector], [0*5+2.5+zeros(1,length(D1_vector)); 0*5+3+zeros(1,length(D1_vector))],'Color',[1 .6 .6]);
plot([D1_vector], [0*5+2.5+zeros(1,length(D1_vector))],'v','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);

a2_vector=0:T2/1000:max(t);
D2_vector=a2_vector+D2/1000;
plot([a2_vector; a2_vector], [1*5+0+zeros(1,length(a2_vector)); 1*5+3+zeros(1,length(a2_vector))],'Color',[1 .6 .6]);
plot([a2_vector], [1*5+3+zeros(1,length(a2_vector))],'^','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);
plot([D2_vector; D2_vector], [1*5+2.5+zeros(1,length(D2_vector)); 1*5+3+zeros(1,length(D2_vector))],'Color',[1 .6 .6]);
plot([D2_vector], [1*5+2.5+zeros(1,length(D2_vector))],'v','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);

a3_vector=0:T3/1000:max(t);
D3_vector=a3_vector+D3/1000;
plot([a3_vector; a3_vector], [2*5+0+zeros(1,length(a3_vector)); 2*5+3+zeros(1,length(a3_vector))],'Color',[1 .6 .6]);
plot([a3_vector], [2*5+3+zeros(1,length(a3_vector))],'^','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);
plot([D3_vector; D3_vector], [2*5+2.5+zeros(1,length(D3_vector)); 2*5+3+zeros(1,length(D3_vector))],'Color',[1 .6 .6]);
plot([D3_vector], [2*5+2.5+zeros(1,length(D3_vector))],'v','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);

a4_vector=0:T4/1000:max(t);
D4_vector=a4_vector+D4/1000;
plot([a4_vector; a4_vector], [3*5+0+zeros(1,length(a4_vector)); 3*5+3+zeros(1,length(a4_vector))],'Color',[1 .6 .6]);
plot([a4_vector], [3*5+3+zeros(1,length(a4_vector))],'^','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);
plot([D4_vector; D4_vector], [3*5+2.5+zeros(1,length(D4_vector)); 3*5+3+zeros(1,length(D4_vector))],'Color',[1 .6 .6]);
plot([D4_vector], [3*5+2.5+zeros(1,length(D4_vector))],'v','MarkerSize',5,'MarkerEdgeColor','red','MarkerFaceColor',[1 .6 .6]);

legend('\tau_{1}','\tau_{2}','\tau_{3}','\tau_{4}')
xlim([min(t) max(t)]);
ylim([-1 19]);

figure;
hold on;
grid on;
box on;
plot(t,debug_data1);
legend('data');
