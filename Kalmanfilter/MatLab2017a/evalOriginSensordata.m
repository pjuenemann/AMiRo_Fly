clear all;
close all; 
clc;

%filename = 'JsonFilesForMatLab/x-richtung_kippen_merged_for_Matlab.txt';
%filename = 'JsonFilesForMatLab/x-richtung_merged_for_Matlab.txt';
 filename = 'JsonFilesForMatLab/y-richtung_kippen_merged_for_Matlab.txt';
% filename = 'JsonFilesForMatLab/y-richtung_merged_for_Matlab.txt';
% filename = 'JsonFilesForMatLab/z-richtung_merged_for_Matlab.txt';
%filename = 'JsonFilesForMatLab/z-richtung_merged_0206.txt';
filename = 'JsonFilesForMatLab/x-richtung_merged_0206.txt';
%filename = 'JsonFilesForMatLab/y-richtung_merged_0206.txt';
[sensordataTWB, sensordataFC] = importFCsensorData(filename);


open_system('ControllerForOriginSensordata');
t_end = sensordataFC(end,1) + (60 - sensordataFC(1,1)) + 0.5;
dtFC = sensordataFC(2,1) - sensordataFC(1,1);
dtTWB = sensordataTWB(2,1) - sensordataTWB(1,1);
dt = dtFC;
t_offsetFC = 60 - sensordataFC(1,1);
sensordataFC(:,1) = sensordataFC(:,1) + t_offsetFC;
idx = find(sensordataFC(:,1) >= 60);
sensordataFC(idx,1) = sensordataFC(idx,1) - 60;

t_offsetTWB = 60 - sensordataTWB(1,1);
sensordataTWB(:,1) = sensordataTWB(:,1) + t_offsetTWB;
idx = find(sensordataTWB(:,1) >= 60);
sensordataTWB(idx,1) = sensordataTWB(idx,1) - 60;


a = 1;
k1 = a;
k2 = a;
k3 = a;
k4 = a;
k5 = a;
k6 = a;
k7 = a;
k8 = a;
k9 = a;
k10 = a;
k11 = a;
k12 = a;

p = 5;
kp1 = p;
kp2 = p;
kp3 = p;
kp4 = p;

d = 10;
kd1 = d;
kd2 = d;
kd3 = d;
kd4 = d;

processNoiseCovariance = eye(12,12)*0.5;
measurementNoiseCovarianceTWB = [0.000114037489420717 -2.82089891064414e-06 1.40417613824518e-05;-2.82089891064414e-06 0.000115657032079071 1.08946618253263e-06;1.40417613824518e-05 1.08946618253263e-06 0.00137780347424666];
measurementNoiseCovarianceDrone = [7.40493968128454e-07 4.00871171116695e-08 2.64850251168023e-07 4.81776544321576e-08 1.70610840898493e-07;4.00871171116695e-08 1.12410457478521e-06 -8.65404287048207e-08 -1.99569229909733e-07 2.12891815399967e-07;2.64850251168023e-07 -8.65404287048207e-08 3.89370394407336e-05 -1.56813743542319e-06 -2.34614557587901e-06;4.81776544321576e-08 -1.99569229909733e-07 -1.56813743542319e-06 3.83263259074627e-05 1.99513110891507e-06;1.70610840898493e-07 2.12891815399967e-07 -2.34614557587901e-06 1.99513110891507e-06 2.60130783647397e-05];
H_TWB = zeros(3,12);
H_TWB(1,1) = 1;
H_TWB(2,2) = 1;
H_TWB(3,3) = 1;

H_Drone = zeros(5,12);
H_Drone(1,7) = 1;
H_Drone(2,8) = 1;
H_Drone(3,9) = 1;
H_Drone(4,10) = 1;
H_Drone(5,11) = 1;

% 1: timestamp
% 2: translationX
% 3: translationY
% 4: translationZ
% 5: rotationX
% 6: rotationY
% 7: rotationZ
dataTWB = sensordataTWB(:,[1:4]);

% 1: timestamp
% 2: gyroscopeX
% 3: gyroscopeY
% 4: gyroscopeZ
% 5: accelerometerX
% 6: accelerometerY
% 7: accelerometerZ
% 8: magnetometerX
% 9: magnetometerY
% 10: magnetometerZ
% 11: baroAlt
% 12: baroTmp
dataDrone = sensordataFC; %(:,[1, 5, 6, 8, 9, 10]);

initialState = zeros(12,1);
initialState([1:3],1) = sensordataTWB(1,[2:4]);
x_d = [sensordataTWB(end,[2:4]), 0];
sim('ControllerForOriginSensordata');
sensorv = sensorValues();
state = simout();
t = state(:,1);
u = simout1();

figure();
subplot(3,1,1);
plot(t, state(:,2), dataTWB(:,1) - repmat(dataTWB(1,1), [size(dataTWB,1), 1]), dataTWB(:,2));
legend('EKF\_{X}', 'Real\_{X}');
xlabel('t/s');
ylabel('Pose\_X/m');
subplot(3,1,2);
plot(t, state(:,3), dataTWB(:,1) - repmat(dataTWB(1,1), [size(dataTWB,1), 1]), dataTWB(:,3));
legend('EKF\_{Y}', 'Real\_{Y}');
xlabel('t/s');
ylabel('Pose\_Y/m');
subplot(3,1,3);
plot(t, state(:,4), dataTWB(:,1) - repmat(dataTWB(1,1), [size(dataTWB,1), 1]), dataTWB(:,4));
legend('EKF\_{Z}', 'Real\_{Z}');
xlabel('t/s');
ylabel('Pose\_Z/m');

figure();
subplot(4,1,1);
plot(t,u(:,1));
legend('u\_z`');
xlabel('t/s');
ylabel('u\_z´/-');
subplot(4,1,2);
plot(t,u(:,2));
legend('u\_psi`');
xlabel('t/s');
ylabel('u\psi´/-');
subplot(4,1,3);
plot(t,u(:,3));
legend('u\_phi');
xlabel('t/s');
ylabel('u\phi/-');
subplot(4,1,4);
plot(t,u(:,4));
legend('u\_theta');
xlabel('t/s');
ylabel('u\theta/-');

%% Plotting FC sensor data
figure();
subplot(3,1,1);
plot(t,sensorValues(:,1),t,sensorValues(:,2),t,sensorValues(:,3));
legend('x','y','z');
title('Gyro');

subplot(3,1,2);
plot(t,sensorValues(:,4),t,sensorValues(:,5),t,sensorValues(:,6));
legend('x','y','z');
title('Acc');

sensorValues(:,[7:9]) = rad2deg(sensorValues(:,[7:9]));
subplot(3,1,3);
plot(t,sensorValues(:,7),t,sensorValues(:,8),t,sensorValues(:,9));
legend('x','y','z');
title('Mag');