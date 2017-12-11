clear;
test = '2';
im = double(imread('data/cameraman.tif'));
im = floor(imresize(im,0.5));
% add in XY coords
[X,Y] = meshgrid(1:size(im,2),1:size(im,1));
data = cat(3,im,X,Y);
% data = lab;
options.debug = 1;
options.tolExit = 1;
options.kernel = 'U';
options.mode = 'A';
bw = [10,8,10];
[pts_out,~,~,clusters,clustersXY] = meanShiftSegment7(data,bw,options);
options.mode = 'M';
[pts_out2,~,~,~,~] = meanShiftSegment7(data,[4,8,10],options);

figure;
im_fig = im;
% im_fig(228:248,80:120) = 255;
im_fig(225:227,77:123) = 255;
im_fig(225:251,77:79) = 255;
im_fig(225:251,121:123) = 255;
im_fig(249:251,77:123) = 255;
subplot(1,3,1);
imshow(im_fig,[1,255]);
subplot(1,3,2);
imshow(pts_out2,[1,255]);
subplot(1,3,3);
imshow(pts_out,[1,255]);

[xx,yy] = meshgrid(1:40,1:20);
zz = im(228:247,75:114);
zz2 = pts_out(228:247,75:114);
zz3 = clusters(228:247,75:114);
zz4 = pts_out2(228:247,75:114);

figure;
subplot(2,2,1);
surf(xx,yy,zz);
subplot(2,2,2);
surf(xx,yy,zz4);
subplot(2,2,3);
surf(xx,yy,zz2);
subplot(2,2,4);
surf(xx,yy,zz3);

figure;
imshow(clusters,[1,255]);

% figure;
% subplot(1,2,1);
% im_fig = im;
% im_fig(455:459,150:229) = 255;
% im_fig(455:504,225:229) = 255;
% im_fig(455:504,150:154) = 255;
% im_fig(500:504,150:229) = 255;
% imshow(im_fig,[1,255]);
% subplot(1,2,2);
% imshow(pts_out,[1,255]);
% [xx,yy] = meshgrid(1:70,1:40);
% zz = im(460:499,155:224);
% zz2 = pts_out(460:499,155:224);
% zz3 = clusters(460:499,155:224);
% 
% figure;
% subplot(1,3,1);
% surf(xx,yy,zz);
% subplot(1,3,2);
% surf(xx,yy,zz2);
% subplot(1,3,2);
% surf(xx,yy,zz3);