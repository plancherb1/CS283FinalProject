im = imread('data/annie.jpg');
% im = imread('data/baboon.tif');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
% data = lab;
options.debug = 1;
options.cluster = 'Y';
[pts_out,clusters] = meanShiftSegment4(data,[25,10,10],options);