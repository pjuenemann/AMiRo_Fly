function C = generateCov
clear all;
close all;
clc;

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
% 11: altitude


M = csvread('cleanflight_data_log_F3.csv', 1, 0);

% Generate Covariance-Matrix for
% altitude, magnetometerZ, accelerometerX, accelerometerY, accelerometerZ, gyroscopeZ
% C = cov(M(:,[11 10 5 6 7 4]));
C = cov(M(:,[2:11]));
end