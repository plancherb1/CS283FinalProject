test = '2';
if test == '1'
    im = 255*im2double(imread('data/cameraman.tif'));
elseif test == '2'
    im = 255*im2double(rgb2gray(imread('data/cassie.png')));
end
% add in XY coords
[X,Y] = meshgrid(1:size(im,2),1:size(im,1));
data = cat(3,im,X,Y);
% data = lab;
options.debug = 1;
options.tolExit = 1e-2;
options.kernel = 'U';
% [pts_out,clusters] = meanShiftSegment3(data,[4,8],options);
[pts_out2,clusters2] = meanShiftSegment4(data,[8,16],options);
figure;
subplot(1,2,1);
imshow(im,[]);
subplot(1,2,2);
imshow(pts_out2,[]);

if test == '1'
    [xx,yy] = meshgrid(1:70,1:40);
    zz = im(460:499,155:224);
    zz2 = pts_out2(460:499,155:224);
else
    [xx,yy] = meshgrid(1:50,1:50);
    zz = im(300:349,75:124);
    zz2 = pts_out2(300:349,75:124);
end
figure;
subplot(1,2,1);
surf(xx,yy,zz)
subplot(1,2,2);
surf(xx,yy,zz2)