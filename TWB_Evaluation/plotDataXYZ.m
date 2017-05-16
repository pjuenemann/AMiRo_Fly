function C = plotDataXYZ( marker_id, change_id, dateinamen )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
dim = 3;
data = zeros(1,dim);
    for datei = dateinamen
        load(datei{1});
        dataLength = length(id);

        ids = {id, id2, id3, id4, id5};
        xs = {tx, tx2, tx3, tx4, tx5};
        ys = {ty, ty2, ty3, ty4, ty5};
        zs = {tz, tz2, tz3, tz4, tz5};
        
        for i = 1:dataLength
            for j = 1:5
                if ids{1,j}(i) == change_id
                    for k = 1:5
                        if k == j
                            break;
                        end
                        if ids{1,k}(i) == marker_id
                            data = [data; xs{1,k}(i) ys{1,k}(i) zs{1,k}(i)];
%                             if (xs{1,k}(i) < -1.48 & xs{1,k}(i) > -1.55 & ys{1,k}(i) < 2.1 & ys{1,k}(i) > 1.4)
%                                  disp(num2str(i));
%                             end
                        end
                    end
                end    
            end
        end
    end
    
    data(1,:) = []; % Erste Zeile löschen
    
    C = cov(data);
        
    figure;
    plot3(data(:,1),data(:,2),data(:,3),'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
    t = ['MarkerID: ' num2str(marker_id) ' 99mm'];
    title(t);
    view(0,90);
end

