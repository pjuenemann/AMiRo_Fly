clearvars;	
close all
clc

marker_id = 1;  % Marker_id: 1 or 15
change_id = 23;

dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger_manipulate.mat'};
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
          
%C = plotDataXYZ(marker_id, change_id, dateinamen);
% covs = surfPerCloud(marker_id, change_id, dateinamen);
[centralCloud covmatrixXY] = centralCloud(marker_id, change_id, dateinamen);
covmatrixREST = generateCov();

Q = zeros(8,8);
Q([1:3],[1:3]) = covmatrixXY([1:3],[1:3]);
Q([3:8],[3:8]) = covmatrixREST;

QQ = zeros(12,12);
QQ([1:3],[1:3]) = covmatrixXY([1:3],[1:3]);
QQ([4:6],[4:6]) = covmatrixXY([1:3],[1:3]);
QQ([7:12],[7:12]) = covmatrixREST;