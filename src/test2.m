im = imread('../data/annie.jpg');
lab = rgb2lab(im);
bandwidth = [100,10];
options.tolExit = 1e-1;
options.maxLoops = 100;
options.debug = 0;

% tic
% [newX] = meanShiftSegmentLABXY(lab,bandwidth,options);
% toc
load('newX');
tic
[newX2] = meanShiftSegmentLABXY_mex(lab,bandwidth,options);
toc

figure;
subplot(1,2,1);
imshow(lab2rgb(newX))
subplot(1,2,2);
imshow(lab2rgb(newX2))
disp('done');