function [ data ] = findcloud( marker_id, change_id, dateinamen )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
    change_id = 23;
    a = 1;
    for datei = dateinamen
        load(datei{1});
        dataLength = length(id);
        last_id = -1;

        ids = {id, id2, id3, id4, id5};
        xs = {tx, tx2, tx3, tx4, tx5};
        ys = {ty, ty2, ty3, ty4, ty5};
        zs = {tz, tz2, tz3, tz4, tz5};
        
        data = zeros(240,10000);
        counter = 0;
        b = 1;
        for i = 1:dataLength
            for j = 1:5
                if ids{1,j}(i) == change_id | ids{1,j}(i) == change_id+1
                    if last_id ~= ids{1,j}(i)
                        %disp([ num2str(last_id) ' ' num2str(counter) ' ' num2str(i)]);
                        counter = 1;
                        if ids{1,j}(i) == change_id
                             a = a+3;
                        end
                        last_id = ids{1,j}(i);
                    else
                        counter = counter + 1;
                    end
                end
                if ids{1,j}(i) == change_id
                    for k = 1:5
                        if k == j
                            break;
                        end
                        if ids{1,k}(i) == marker_id
                            if b == 1
                                disp(['i: ' num2str(i)]);
                                b = 0;
                            end
                            data(a,counter) = xs{1,k}(i);
                            data(a+1,counter) = ys{1,k}(i);
                            data(a+2,counter) = zs{1,k}(i);
%                             if (xs{1,k}(i) < -1.48 & xs{1,k}(i) > -1.55 & ys{1,k}(i) < 2.1 & ys{1,k}(i) > 1.4)
%                                  disp(num2str(i));
%                             end
                        end
                    end
                end 
            end
        end
        %disp(['a: ' num2str(a)]);
    end
    delete = zeros(1,240);
    for i = 1:240
        if sum(data(i,:)) == 0
            delete(1,i) = i;
        end
    end
    for i = 1:240
        if delete(1,i) > 0
            data(delete(1,i),:) = [];
            delete(1,:) = delete(1,:) - 1;
        end
    end
    figure;
    plot3(data(:,1),data(:,2),data(:,3),'o','MarkerSize',3,'MarkerEdgeColor','b','MarkerFaceColor','b');
    t = ['MarkerID: ' num2str(marker_id) ' 99mm'];
    title(t);
end

