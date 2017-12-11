im = imread('../data/annie.jpg');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
bandwidth = [100,10];
% data = lab;
% bandwidth = 100;

l = size(data,1);
w = size(data,2);
feature_size = size(data,3);
X = reshape(data,l*w,feature_size)';
currX = X;
activeIndicies = 1:max(size(X));
tic
[newX] = meanShiftLABXY(X,currX,bandwidth,activeIndicies);
toc
tic
[newX2] = meanShiftLABXY_mex(X,currX,bandwidth,activeIndicies);
toc

Xout = reshape(newX(1:3,:)',l,w,[]);
X2out = reshape(newX2(1:3,:)',l,w,[]);
figure;
subplot(1,2,1);
imshow(lab2rgb(Xout))
subplot(1,2,2);
imshow(lab2rgb(X2out))

disp('done');