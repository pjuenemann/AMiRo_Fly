clearvars;	
close all
clc

change_id = 23;
dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger.mat'};
%dateinamen = {'box1/16-12-14_11-34-28_rsbag_merger.mat'};
%dateinamen = {'box2/16-12-14_13-12-40_rsbag_merger.mat'};
%dateinamen = {'box3/16-12-14_13-34-49_rsbag_merger.mat'};
dateinamen = {'box4/17-01-12_14-21-27_rsbag_merger.mat'};
%dateinamen = {'box5/17-01-12_15-18-07_rsbag_merger.mat'};

%dateinamen = {'floor/16-12-14_11-02-51_rsbag_merger.mat',...
              'box1/16-12-14_11-34-28_rsbag_merger.mat',...
              'box2/16-12-14_13-12-40_rsbag_merger.mat',...
              'box3/16-12-14_13-34-49_rsbag_merger.mat',...
              'box4/17-01-12_14-21-27_rsbag_merger.mat',...
%              'box5/17-01-12_15-18-07_rsbag_merger.mat'};


%dateinamen = {'box4/16-12-15_16-44-14_rsbag_merger.mat'};
%dateinamen = {'box5/16-12-15_17-53-37_rsbag_merger.mat'};

dateinr = 1;

load(dateinamen{dateinr});
dataLength = length(id);


counter1 = 0;
counter15 = 0;
for i = 1:dataLength
    if id4(i) == change_id
        if id(i) == 1
            counter1 = counter1 + 1;
        end
        if id2(i) == 15
            counter15 = counter15 + 1;
        end
    end
end

x1 = zeros(1,counter1);
y1 = zeros(1,counter1);
z1 = zeros(1,counter1);
x15 = zeros(1,counter15);
y15 = zeros(1,counter15);
z15 = zeros(1,counter15);

counter1 = 0;
counter15 = 0;
for i = 1:dataLength
    if id4(i) == change_id
        if id(i) == 1
            counter1 = counter1 + 1;
            x1(counter1) = tx(i);
            y1(counter1) = ty(i);
            z1(counter1) = tz(i);
        end
        if id2(i) == 15
            counter15 = counter15 + 1;
            x15(counter15) = tx2(i);
            y15(counter15) = ty2(i);
            z15(counter15) = tz2(i);
        end
    end
end

figure();
%plot(x1,y1,'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
plot3(x1,y1,z1,'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
title('MarkerID: 1 99mm');
figure();
%plot(x15,y15,'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
plot3(x15,y15,z15,'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
title('MarkerID: 15 80mm');