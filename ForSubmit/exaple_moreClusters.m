clear;
bw = [8,8,20];
[pts_out,xy_out,csize,clusters,cxy] = computeImage(imresize(imread('data/Lake2.jpg'),0.1),bw);
[pts_out2,xy_out2,csize2,clusters2,cxy2] = computeImage(imread('data/city.jpg'),bw);
[pts_out3,xy_out3,csize3,clusters3,cxy3] = computeImage(imresize(imread('data/ski.jpg'),0.75),bw);
[pts_out4,xy_out4,csize4,clusters4,cxy4] = computeImage(imresize(imread('data/nye.jpg'),0.1),bw);

figure;
subplot(1,2,1);
imshow(imresize(imread('data/Lake2.jpg'),0.1));
subplot(1,2,2);
imshow(lab2rgb(clusters));

figure;
subplot(1,2,1);
imshow(imread('data/city.jpg'));
subplot(1,2,2);
imshow(lab2rgb(clusters2));

figure;
subplot(1,2,1);
imshow(imresize(imread('data/ski.jpg'),0.75));
subplot(1,2,2);
imshow(lab2rgb(clusters3));

figure;
subplot(1,2,1);
imshow(imresize(imread('data/nye.jpg'),0.1));
subplot(1,2,2);
imshow(lab2rgb(clusters4));

% computeBorder(clusters);

function [pts_out,xy_out,csize,clusters,cxy] = computeImage(im,bw)
    lab = rgb2lab(im);
    % add in XY coords
    [X,Y] = meshgrid(1:size(im,2),1:size(im,1));
    data = cat(3,lab,X,Y);
    options.debug = 1;
    options.mode = 'A';
    [pts_out,xy_out,csize,clusters,cxy] = meanShiftSegmentFinal(data,bw,options);
    figure;
    subplot(1,2,1);
    imshow(im);
    subplot(1,2,2);
    imshow(lab2rgb(pts_out));
    subplot(1,3,3);
    imshow(lab2rgb(clusters));
end

function computeBorder(clusters)
    l = size(clusters,1);
    w = size(clusters,2);
    figure;
    imshow(lab2rgb(clusters));
    hold on;
    clustersRow = reshape(clusters,l*w,[]);
    cluster_list = unique(clustersRow,'rows');
    for idx=1:size(cluster_list,1)
        ids = unique((sum((clustersRow - cluster_list(idx,:)).^2,2) == 0).*(1:l*w)');
        ids = ids(any(ids ~= 0,2),:);
        [y,x] = ind2sub([l,w],ids);
        k = convhull(x,y);
        plot(x(k),y(k),'w');
    end
end