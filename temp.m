clear;
load('temp2.mat');
figure;
M = 50;
clusters = zeros(l,w,1);
while 1
    curr_max_size = max(cluster_size(:));
    [r,c] = find(curr_max_size == cluster_size,1);
    startY = max(r-bandwidth(2),1);
    endY = min(r+bandwidth(2),l);
    startX = max(c-bandwidth(2),1);
    endX = min(c+bandwidth(2),w);
    color = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) <= bandwidth(1).^2;
    distance = sum((currX(startY:endY,startX:endX,end-1:end) - currX(r,c,end-1:end)).^2,3) <= bandwidth(2).^2;
    valid = color.*distance.*(clusters(startY:endY,startX:endX)==0);
    rest = ~valid.*clusters(startY:endY,startX:endX);
    if curr_max_size > M
        clusters(startY:endY,startX:endX) = valid.*currX(r,c,1:end-2) + rest;
        cluster_size(startY:endY,startX:endX) = ~valid.*cluster_size(startY:endY,startX:endX);
    else
        rest(rest==0) = NaN;
        horizontal = fillmissing(rest,'movmedian',floor(M/4),1);
        vertical = fillmissing(rest,'movmedian',floor(M/4),2);
        clusters(startY:endY,startX:endX) = (horizontal + vertical)/2;
        cluster_size(startY:endY,startX:endX) = 0;
    end
    left = nnz(cluster_size>0);
    imshow(clusters,[]);
    disp(left);
    if  left == 0
        break;
    end
end