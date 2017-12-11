clear;
load('temp3.mat')
imshow(computeClusters(currX,bandwidth,cluster_sizes,bandwidth(3)),[]);

function [clusters] = computeClusters(currX,bandwidth,cluster_sizes,M)
    l = size(currX,1);
    w = size(currX,2);
    features = size(currX,3)-2;
    clusters = zeros(l,w,features);
    % loop until all clusters are assigned
    while nnz(cluster_sizes>0)
        % find the biggest cluster center left
        curr_max_size = max(cluster_sizes(:));
        [r,c] = find(curr_max_size == cluster_sizes,1);
        startY = max(r-bandwidth(2),1);
        endY = min(r+bandwidth(2),l);
        startX = max(c-bandwidth(2),1);
        endX = min(c+bandwidth(2),w);
        % find the points that support it in the window that are unassigned
        color = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) <= bandwidth(1).^2;
        distance = sum((currX(startY:endY,startX:endX,end-1:end) - currX(r,c,end-1:end)).^2,3) <= bandwidth(2).^2;
        valid = color.*distance.*(sum(clusters(startY:endY,startX:endX,:),3)==0);
        % find the values that remain
        rest = ~valid.*clusters(startY:endY,startX:endX,:);
        % if a large cluster assign all values to the cluster center and
        % remove all of those values from being a future cluster center
        if nnz(rest==0) > M
            clusters(startY:endY,startX:endX,:) = valid.*currX(r,c,1:end-2) + rest;
            cluster_sizes(startY:endY,startX:endX) = ~valid.*cluster_sizes(startY:endY,startX:endX);
        % else fill with the value from the nearest valid cluster
        else
            rest(rest==0) = NaN;
            clusters(startY:endY,startX:endX,:) = fillmissing(rest,'nearest');
            cluster_sizes(startY:endY,startX:endX) = 0;
        end
    end
end