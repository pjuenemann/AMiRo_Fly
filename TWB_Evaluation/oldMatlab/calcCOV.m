clearvars;	
close all
clc

change_id = 23;
numOfData = 3;
dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger.mat'};
dateinamen = {'box1/16-12-14_11-34-28_rsbag_merger.mat'};
dateinamen = {'box2/16-12-14_13-12-40_rsbag_merger.mat'};
dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger.mat',...
              'box1/16-12-14_11-34-28_rsbag_merger.mat',...
              'box2/16-12-14_13-12-40_rsbag_merger.mat',...
              'box3/16-12-14_13-34-49_rsbag_merger.mat'};
%dateinamen = {'box3/16-12-14_13-34-49_rsbag_merger.mat'};
%dateinamen = {'box4/16-12-15_16-44-14_rsbag_merger.mat'};
%dateinamen = {'box5/16-12-15_17-53-37_rsbag_merger.mat'};

dim = 3;
counter1 = zeros(1,numOfData);
counter15 = zeros(1,numOfData);

xx1 = 0;
yy1 = 0;
zz1 = 0;
xx15 = 0;
yy15 = 0;
zz15 = 0;
for dateinr = 1:numOfData
    load(dateinamen{dateinr});
    dataLength = length(id);
    for i = 1:dataLength
        if id(i) == 1
            counter1(1,dateinr) = counter1(1,dateinr) + 1;
        end
        if id2(i) == 15
            counter15(1,dateinr) = counter15(1,dateinr) + 1;
        end
    end

    x1 = zeros(1,counter1(1,dateinr));
    y1 = zeros(1,counter1(1,dateinr));
    z1 = zeros(1,counter1(1,dateinr));
    x15 = zeros(1,counter15(1,dateinr));
    y15 = zeros(1,counter15(1,dateinr));
    z15 = zeros(1,counter15(1,dateinr));

    counter1(1,dateinr) = 0;
    counter15(1,dateinr) = 0;
    for i = 1:dataLength
        if id4(i) == change_id
            if id(i) == 1
                counter1(1,dateinr) = counter1(1,dateinr) + 1;
                x1(counter1(1,dateinr)) = tx(i);
                y1(counter1(1,dateinr)) = ty(i);
                z1(counter1(1,dateinr)) = tz(i);
            end
            if id2(i) == 15
                counter15(1,dateinr) = counter15(1,dateinr) + 1;
                x15(counter15(1,dateinr)) = tx2(i);
                y15(counter15(1,dateinr)) = ty2(i);
                z15(counter15(1,dateinr)) = tz2(i);
            end
        end
    end
    xx1 = [xx1 x1];
    yy1 = [yy1 y1];
    zz1 = [zz1 z1];
    xx15 = [xx15 x15];
    yy15 = [yy15 y15];
    zz15 = [zz15 z15];       
end

xx1(1) = [];
yy1(1) = [];
zz1(1) = [];
xx15(1) = [];
yy15(1) = [];
zz15(1) = [];
A1 = [xx1' yy1' zz1'];
A15 = [xx15' yy15' zz15'];

COV1 = cov(A1);
COV15 = cov(A15);
