clear;
im = imread('data/bc2.jpg');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
bw = [8,12,20];
options.debug = 1;
options.mode = 'M';
[pts_out,xy_out,~,~,~] = meanShiftSegmentFinal(data,bw,options);
msPts = cat(3,pts_out,xy_out);
options.mode = 'C';
options.cs = cluster_sizes;
[~,~,~,clusters,~] = meanShiftSegmentFinal(data,bw,options);
options.smooth = 1;
options.smoothLevel = 0.3;
[~,~,~,clusters2,~] = meanShiftSegmentFinal(data,bw,options);

figure;
subplot(2,2,1);
imshow(im);
subplot(2,2,2);
imshow(lab2rgb(pts_out));
subplot(2,2,3);
imshow(lab2rgb(clusters));
subplot(2,2,4);
imshow(lab2rgb(clusters2));