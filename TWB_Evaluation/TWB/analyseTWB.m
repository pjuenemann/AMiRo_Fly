clearvars;	
close all
clc

marker_id = 1;  % Marker_id: 1 or 15
change_id = 23;

% Wähle einen oder mehrere Datensätze aus, die analysiert werden sollen.

%dateinamen = {'box1/16-12-14_11-34-28_rsbag_merger_manipulate.mat'};
%dateinamen = {'box2/16-12-14_13-12-40_rsbag_merger_manipulate_2.mat'};
%dateinamen = {'box3/16-12-14_13-34-49_rsbag_merger.mat'};
%dateinamen = {'box4/17-01-12_14-21-27_rsbag_merger.mat'};
%dateinamen = {'box5/17-01-12_15-18-07_rsbag_merger_manipulate_2.mat'};

dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger_manipulate.mat',...
              'box1/16-12-14_11-34-28_rsbag_merger_manipulate.mat',...
              'box2/16-12-14_13-12-40_rsbag_merger_manipulate_2.mat',...
              'box3/16-12-14_13-34-49_rsbag_merger.mat',...
              'box4/17-01-12_14-21-27_rsbag_merger.mat',...
              'box5/17-01-12_15-18-07_rsbag_merger_manipulate_2.mat'};
% dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger_manipulate.mat',...
%               'box1/16-12-14_11-34-28_rsbag_merger_manipulate.mat'};          
          

% Alte Skripte. Aktuell nicht zu verwenden...
%C = plotDataXYZ(marker_id, change_id, dateinamen);
% covs = surfPerCloud(marker_id, change_id, dateinamen);


% Die Funktion centralCloud bestimmt alle Punktwolken, die alle dieselbe
% Größe besitzen, und bestimmt anschließend die Kovarianzmatrix mit den
% Zufallsvariablen x_twb, y_twb, z_twb.
[centralCloud covmatrixTWB] = centralCloud(marker_id, change_id, dateinamen);

% generateCov generiert aus den aufgenommenen Sensordaten des FC die
% Kovarianzmatrix für dessen Sensoren.
% Die Zufallsvariablen sind:
% 1: gyroscopeX
% 2: gyroscopeY
% 3: gyroscopeZ
% 4: accelerometerX
% 5: accelerometerY
% 6: accelerometerZ
% 7: magnetometerX
% 8: magnetometerY
% 9: magnetometerZ
% 10: altitude
covmatrixDrone = generateCov();

% Q ist die Kovarianzmatrix mit den Zufallsvariablen:
% x_twb,y_twb,z_twb,magnetometerZ,accelerometerX,accelerometerY,accelerometerZ,
% gyroscopeZ
Q = zeros(8,8);
Q([1:3],[1:3]) = covmatrixTWB([1:3],[1:3]);
Q([4:8],[4:8]) = covmatrixDrone([9,4,5,6,3],[9,4,5,6,3]);


% QQ ist die Kovarianzmatrix mit den Zufallsvariablen:
% accelerometerX,accelerometerY,magnetometerX,magnetometerY,magnetometerZ
QQ = zeros(5,5);
QQ = covmatrixDrone([4,5,7,8,9],[4,5,7,8,9]);

