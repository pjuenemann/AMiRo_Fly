function [ centralCloud, covs] = central_cloud( marker_id, change_id, dateinamen )
% Mit dieser Funktion werden alle Datenpunkte, die verwendet werden sollen,
% gefiltert, aufgelistet und in gleich gro�e Punktwolken unterteilt.
% Anschlie�end werden alle Datenpunkte zentralisiert, indem das
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
                            if ids{1,k}(i) == change_id     % Aufnahme l�uft
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
    minDataPerCloud = min(minDataPerCloud)-1;  % Minimale Wolkengr��e
    disp(['Minimale Wolkengr��e: ' num2str(minDataPerCloud)]);

    covs = zeros(1,3); % Kovarianzmatrizen je Punktwolke
    meanClouds = zeros(1,3);  % Durchschnitt je Dimension je Punktwolke
    data(1,:) = [];
    numClouds = 0;  % Anzahl Wolken
    last_cloud_start = 1;
    counter = 0;
    centralCloud = zeros(1,3);
    for i = 1:size(data,1)
        if counter < minDataPerCloud
            counter = counter + 1;
            centralCloud = [centralCloud; data(i,:)];
            if(size(centralCloud,1) == 10989)
                0;
            end
            if(sum(centralCloud(1,:))) == 0
                centralCloud(1,:) = [];
            end
        end
        if sum(data(i,:)) == 0
            %covs = [covs; cov(data([last_cloud_start:i-1],:))];
            meanClouds = [meanClouds; mean(data([last_cloud_start:i-1],:))];
            if(sum(meanClouds(1,:))) == 0
                meanClouds(1,:) = [];
            end
            for j = 1:3 % Mittelwert in jeder Komponente subtrahieren
                centralCloud([numClouds*minDataPerCloud+1:numClouds*minDataPerCloud+minDataPerCloud],j) = ...
                    centralCloud([numClouds*minDataPerCloud+1:numClouds*minDataPerCloud+minDataPerCloud],j) - ...
                    meanClouds(numClouds+1,j);
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
    disp(['Anzahl Punktwolken: ' num2str(numClouds)]);
    plot3(centralCloud(:,1),centralCloud(:,2),centralCloud(:,3),'o',...
        'MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
    covs = cov(centralCloud);
end