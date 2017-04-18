clear all;
close all; 
clc;

open_system('ControllerNL');
t_end = 10;
Ts = 0.05;
dt = 1/100;

k1 = 0.5;
k2 = 0.5;
k3 = 0.5;
k4 = 0.5;
k5 = 0.5;
k6 = 0.5;
k7 = 0.5;
k8 = 0.5;
k9 = 0.5;
k10 = 0.5;
k11 = 0.5;
k12 = 0.5;

a = 0.2;
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

p = 100;
kp1 = p;
kp2 = p;
kp3 = p;
kp4 = p;

d = 50;
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

t = [0:dt:t_end]';
x = linspace(0,0,size(t,1))';
y = linspace(0,0,size(t,1))';
z = linspace(0,5,size(t,1))';
v_x = linspace(0,0,size(t,1))';
v_y = linspace(0,0,size(t,1))';
phi = linspace(0,0,size(t,1))';
theta = linspace(0,0,size(t,1))';
psi = linspace(0,0,size(t,1))';

data_TWB = [t, x, y, z];
data_Drone = [t, v_x, v_y, phi, theta, psi];
%delta = 1/1000;
%z = awgn(z,delta,'measured');

x_d = [0 0 5 0];
sim('ControllerNL');
x_z = simout();
plot(t,x_z, t,z);
legend('EKF_z', 'real_z');