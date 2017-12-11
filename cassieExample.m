% load in the image in grayscale
im = 255*im2double(rgb2gray(imread('data/cassie.png')));
% add in XY coords
[X,Y] = meshgrid(1:size(im,2),1:size(im,1));
data = cat(3,im,X,Y);
% set options
options.debug = 1;
options.tolExit = 1e-2;
options.kernel = 'U';
[pts_out,clusters] = meanShiftSegment4(data,[8,16,50],options);

% display figures -- first the image
imfig = im;
imfig(295:299,70:129) = 0;
imfig(350:354,70:129) = 0;
imfig(295:354,70:74) = 0;
imfig(295:354,125:129) = 0;
figure;
subplot(1,2,1);
imshow(imfig,[]);
title('Original Image');
subplot(1,2,2);
imshow(pts_out,[]);
title('(hs,hr) = (16,8)');

figure;
subplot(1,3,1);
imshow(imfig,[]);
title('Original Image');
subplot(1,3,2);
imshow(pts_out,[]);
title('(hs,hr) = (16,8)');
subplot(1,3,3);
imshow(clusters,[]);
title('(hs,hr,M) = (16,8,50)');

% display figures -- then the subsection plots
[xx,yy] = meshgrid(1:50,1:50);
zz = im(300:349,75:124);
zz2 = pts_out(300:349,75:124);
zz3 = clusters(300:349,75:124);

figure;
subplot(1,3,1);
surf(xx,yy,zz)
subplot(1,3,2);
surf(xx,yy,zz2)
subplot(1,3,3);
surf(xx,yy,zz3);

figure;
subplot(1,2,1);
surf(xx,yy,zz2)
subplot(1,2,2);
surf(xx,yy,zz3);