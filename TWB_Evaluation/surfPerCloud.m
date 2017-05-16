function [ covs ] = centralCloud( marker_id, change_id, dateinamen )
% Mit dieser Funktion werden alle Datenpunkte, die verwendet werden sollen,
% gefiltert, aufgelistet und in gleich große Punktwolken unterteilt.
% Anschließend werden alle Datenpunkte zentralisiert, indem das
% arithmetische Mittel jeder Punktwolke subtrahiert wird.

    change_id = 23;
    data = zeros(1,3);
    minDataPerCloud = 0;
    for datei = dateinamen
        load(datei{1});
        dataLength = length(id);
        isRecord = 0;   % 0: keine Aufnahme; 1: Aufnahme
        minDataPerCloudCounter = 0;        
        
        ids = {id, id2, id3, id4, id5};
        xs = {tx, tx2, tx3, tx4, tx5};
        ys = {ty, ty2, ty3, ty4, ty5};
        zs = {tz, tz2, tz3, tz4, tz5};
        
        for i = 1:dataLength
            for j = 1:5
                if ids{1,j}(i) == marker_id
                    for k = j:5
                        if ids{1,k}(i) == change_id | ids{1,k}(i) == (change_id + 1)  
                            if ids{1,k}(i) == change_id     % Aufnahme läuft
                                data = [data; xs{1,j}(i) ys{1,j}(i) zs{1,j}(i)];
                                isRecord = 1;
                                minDataPerCloudCounter = minDataPerCloudCounter + 1;
                                break;
                            else    % keine Aufnahme
                                if isRecord == 1
                                   minDataPerCloud = [minDataPerCloud minDataPerCloudCounter];
                                   minDataPerCloudCounter = 0;
                                   data = [data; 0 0 0];
                                end
                                isRecord = 0;
                            end
                        end
                    end
                    break;
                end
            end
        end 
    end
    
    minDataPerCloud(1) = [];
    minDataPerCloud = min(minDataPerCloud)-1;  % Minimale Wolkengröße
    disp(['Minimale Wolkengröße: ' num2str(minDataPerCloud)]);

    data(1,:) = [];
    numClouds = 0;  % Anzahl Wolken
    last_cloud_start = 1;
    counter = 0;
    covs = zeros(1,3); % Kovarianzmatrizen je Punktwolke
    meanClouds = zeros(1,3);  % Durchschnitt je Dimension je Punktwolke
    for i = 1:size(data,1)
        if counter < minDataPerCloud
            counter = counter + 1;        
        end
        if sum(data(i,:)) == 0
            covs = [covs; cov(data([last_cloud_start:i-1],:))];
            if(sum(covs(1,:))) == 0
                covs(1,:) = [];
            end
            meanClouds = [meanClouds; mean(data([last_cloud_start:i-1],:))];
            if(sum(meanClouds(1,:))) == 0
                meanClouds(1,:) = [];
            end
            last_cloud_start = i;
            numClouds = numClouds + 1;
            data(i,:) = [];
            counter = 0;
        end
        if i > size(data,1)
            break;
        end
    end
    
    standardabw_geordnet = zeros(3,numClouds);
    for i = 1:numClouds
        [a b c] = pcacov(covs([3*i-2:3*i],:));
        standardabw_geordnet(:,i) = real(sqrt(eig(covs([3*i-2:3*i],:))));
    end
    figure();
    plot3(meanClouds(:,1),meanClouds(:,2),standardabw_geordnet(1,:)','o');
    hold on;

    x_int = linspace(-10,0,200);
    y_int = linspace(10,0,200);
    y_int = y_int(:);
    
%     figure();
%     subplot(3,1,1);
%     [X Y Z] = griddata(meanClouds(:,1),meanClouds(:,2),...
%         standardabw_geordnet(1,:),x_int,y_int,'cubic');
%     surf(X,Y,Z);
    trisurf(delaunay(meanClouds(:,1),meanClouds(:,2)), meanClouds(:,1),meanClouds(:,2),...
         standardabw_geordnet(1,:)');
    title('Standardabweichung der x-Achse');
    xlabel('x in m');
    ylabel('y in m');
    zlabel('\sigma in m');
%         figure();
%         [X Y Z] = meshgrid(meanClouds(:,1),meanClouds(:,2),...
%         standardabw_geordnet(1,:));
%         surf(X,Y,Z);
    
    figure();
    plot3(meanClouds(:,1),meanClouds(:,2),standardabw_geordnet(2,:)','o');
    hold on;
%     subplot(3,1,2);
%     [X Y Z] = griddata(meanClouds(:,1),meanClouds(:,2),...
%         standardabw_geordnet(2,:),x_int,y_int,'cubic');
%     surf(X,Y,Z);
    trisurf(delaunay(meanClouds(:,1),meanClouds(:,2)), meanClouds(:,1),meanClouds(:,2),...
         standardabw_geordnet(2,:)');
    title('Standardabweichung der y-Achse');
    xlabel('x in m');
    ylabel('y in m');
    zlabel('\sigma in m');
    
    figure();
    plot3(meanClouds(:,1),meanClouds(:,2),standardabw_geordnet(3,:)','o');
    hold on;
%     subplot(3,1,3);
%     [X Y Z] = griddata(meanClouds(:,1),meanClouds(:,2),...
%         standardabw_geordnet(3,:),x_int,y_int,'cubic');
%     surf(X,Y,Z);
    trisurf(delaunay(meanClouds(:,1),meanClouds(:,2)), meanClouds(:,1),meanClouds(:,2),...
         standardabw_geordnet(3,:)');
    title('Standardabweichung der z-Achse');
    xlabel('x in m');
    ylabel('y in m');
    zlabel('\sigma in m');
    disp(['Anzahl Punktwolken: ' num2str(numClouds)]);    
end