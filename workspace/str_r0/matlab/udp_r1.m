clear all;
clc;
delete(instrfind);

u=udp('169.254.88.200',8888,'localPort',56200);
fopen(u);

%this causes a reset
s=serial('COM14', 'BaudRate', 115200,'Terminator','LF','TimeOut',20);
fopen(s);
fclose(s);


try
    close all;
    figure;
    hold on;
    grid on;
    box on;
    % ylim([0 360]);
    data1_k_1=0;
    data2_k_1=0;
    data3_k_1=0;
    for i=1:1:50
        data=fscanf(u,'%f%f%f');%fread(u);    
        plot([i-1 i],[data1_k_1 data(1)],'-b');
        plot([i-1 i],[data2_k_1 data(2)],'-r');
        plot([i-1 i],[data3_k_1 data(3)],'-g');
        xlim([i-50 i]);
        drawnow;
        data1_k_1=data(1);
        data2_k_1=data(2);
        data3_k_1=data(3);
    end
    
% text_char=char(text)'
% text=fread(u);
% text_char=char(text)'
% text=fread(u);
% text_char=char(text)'

% fwrite(u,'hi!!!');
% pause(1);
% text=fread(u);
% text_char=char(text)'
% pause(1);
% fwrite(u,'bye!!!');
% pause(1);
% text=fread(u);
% text_char=char(text)'
% pause(1);


catch Me
    Me.identifier
    close all;
    disp("Error. Closing udp connection...");
    fclose(u);
    return;
end
% fclose(u);
