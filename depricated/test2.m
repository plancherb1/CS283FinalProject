im = imread('data/baboon.tif');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
% data = lab;
options.debug = 1;
options.tolExit = 1;
[pts_out,clusters] = meanShiftSegment3(data,[16,32],options);
figure;
subplot(1,2,1);
imshow(im);
subplot(1,2,2);
imshow(lab2rgb(pts_out));