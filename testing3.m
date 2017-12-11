clear;
% setup the problem
im = imread('data/baboon.tif');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
options.debug = 1;
options.mode = 'M';

bw = [8,8,20]; %first is colors, 2nd is space
[pts,~,~] = meanShiftSegment6(data,bw,options);
pts  = lab2rgb(pts);

bw2 = [16,8,20];
[pts2,~,~] = meanShiftSegment6(data,bw2,options);
pts2  = lab2rgb(pts2);

figure;
subplot(1,3,1);
imshow(im);
title('Original Image');
subplot(1,3,2);
imshow(pts);
title(['(hs,hr) = (',num2str(bw(2)),',',num2str(bw(1)),')']);
subplot(1,3,3);
imshow(pts2);
title(['(hs,hr) = (',num2str(bw2(2)),',',num2str(bw2(1)),')']);
% title('Clustered Image');
