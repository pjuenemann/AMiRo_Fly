clearvars;
close all;
% dateiname = input('Bitte Nam16-06-06-13-01.tide.jsonen der .Json Datei eingeben: ','s');
dateiname = 'box2/16-12-14_13-12-40_rsbag_merger_manipulate_2.tide';
%dateiname = 'box1/16-12-14_11-34-28_rsbag_merger_manipulate.tide';
[zeit,id,tx,ty,tz,rx,ry,rz,id2,tx2,ty2,tz2,rx2,ry2,rz2,id3,tx3,ty3,tz3,rx3,ry3,rz3,id4,tx4,ty4,tz4,rx4,ry4,rz4,id5,tx5,ty5,tz5,rx5,ry5,rz5]=importfile1([dateiname,'.json']);
dateiname = '16-12-14_13-12-40_rsbag_merger_manipulate_2';
save([dateiname,'.mat']);