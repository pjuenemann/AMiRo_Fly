function [ data, data2, standardabw , standardabw_geordnet ] = findcloud_2( marker_id, change_id, dateinamen )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
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
%                             ids{1,k}(i) = [];
%                         else
                            if ids{1,k}(i) == change_id     % Aufnahme läuft
                                data = [data; xs{1,j}(i) ys{1,j}(i) zs{1,j}(i)];
                                isRecord = 1;
                                minDataPerCloudCounter = minDataPerCloudCounter + 1;
                                break;
                            else    % keine Aufnahme
                                if isRecord == 1
                                   minDataPerCloud = [minDataPerCloud minDataPerCloudCounter];
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
        minDataPerCloud(1) = [];
        minDataPerCloud = min(minDataPerCloud)
        %data(end,:) = [];
        data2 = zeros(1,3); % Kovarianzmatrizen je Punktwolke
        meanClouds = zeros(1,3);  % Durchschnitt je Dimension je Punktwolke
        data(1,:) = [];
        numClouds = 0;  % Anzahl Wolken
        figure(1);
        last_cloud_start = 1;
        counter = 0;
        for i = 1:size(data,1)
            if counter < minDataPerCloud
                counter = counter + 1;
            end
            if sum(data(i,:)) == 0
                data2 = [data2; cov(data([last_cloud_start:i-1],:))];
                %figure(1);
                %plot3(data([last_cloud_start:i-1]),data([last_cloud_start:i-1],2),data([last_cloud_start:i-1],3),'g+');
                %hold on;
                meanClouds = [meanClouds; mean(data([last_cloud_start:i-1],:))];% ...
                        %mean(data([last_cloud_start:i-1],2))...
                        %mean(data([last_cloud_start:i-1],3))];
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
        data2(1,:) = [];
        meanClouds(1,:) = [];
        detscov = zeros(1,1);
        % [xx yy] = meshgrid(meanClouds(:,1),meanClouds(:,2));
        standardabw = zeros(3,numClouds);
        standardabw_geordnet = zeros(3,numClouds);
        for i = 1:numClouds
%              detscov(i,1) = det(data2([3*i-2:3*i],:)); 
%             % detscov(i,1) = det(cov(xx, yy, zz));
%             
%             [U,L] = eig(data2([3*i-2:3*i],:));
%             % L: eigenvalue diagonal matrix
%             % U: eigen vector matrix, each column is an eigenvector
% 
%             % For N standard deviations spread of data, the radii of the eliipsoid will
%             % be given by N*SQRT(eigenvalues).
% 
%             N = 1; % choose your own N
%             radii = N*sqrt(diag(L));
% 
%             % generate data for "unrotated" ellipsoid
%             [xc,yc,zc] = ellipsoid(0,0,0,radii(1),radii(2),radii(3));
% 
%             % rotate data with orientation matrix U and center mu
%             aaa = kron(U(:,1),xc); 
%             bbb = kron(U(:,2),yc); 
%             ccc = kron(U(:,3),zc);
% 
%             data3 = aaa+bbb+ccc;
%             n = size(data3,2);
%             
%             mu = meanClouds(numClouds,:);
%             x = data3(1:n,:)+mu(1); 
%             y = data3(n+1:2*n,:)+mu(2); 
%             z = data3(2*n+1:end,:)+mu(3);
%             %[x y z] = ellipsoid(mu(1),mu(2),mu(3),x,y,z);
%             % now plot the rotated ellipse
%             % sc = surf(x,y,z); shading interp; colormap copper
%             % figure;
%             h = surfl(x, y, z); colormap copper
%             title('actual ellipsoid represented by mu and Cov')
%             axis equal
%             alpha(0.7)
            hold on;
            %plot3(data([3*i-2:counter*i],1),data([3*i-2:counter*i],2),data([3*i-2:counter*i],3),'*')
            [a b c] = pcacov(data2([3*i-2:3*i],:));
            standardabw(:,i) = sqrt(b);
            standardabw_geordnet(:,i) = sqrt(eig(data2([3*i-2:3*i],:)));
            figure(1);
            hold on;
            mu = meanClouds(i,:);
            plot3(mu(1),mu(2),mu(3),'+r');
%             [x y z] = ellipsoid(mu(1),mu(2),mu(3),stan(1,i),stan(2,i),stan(3,i));
%             surf(x,y,z);
        end
        standardabw_geordnet = real(standardabw_geordnet);
        plot3(data(:,1),data(:,2),data(:,3),'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
        t = ['MarkerID: ' num2str(marker_id) ' 99mm'];
        title(t);
        view(0,90);
        
        figure();
        plot3(meanClouds(:,1), meanClouds(:,2), standardabw_geordnet(1,:));
        suX = zeros(6,1);
        suY = zeros(6,1);
        suZ = zeros(6,6);
        cc = 1;
        for i = 1:6:36
            suX(cc,1) = mean(meanClouds([i:i+5],1));
            suY(cc,1) = mean(meanClouds([i:6:i+5],2));
            cc = cc + 1;
        end
        
%         cc = 0;
%         for i = 1:2:5
%             for j = 1:6
%                 cc = cc + 1;
%                 suZ(j,i) = standardabw_geordnet(3,cc);
%                 suZ(7-j,i+1) = standardabw_geordnet(3,cc+6);
%             end
%             cc = cc + 6;
%         end
%         suZ = suZ';
%         figure();
%         mesh(suX, suY, suZ);
        %figure();
        %plot3(meanClouds(:,1),meanClouds(:,2),detscov);
    end

end