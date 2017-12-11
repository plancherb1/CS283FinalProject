% setup the problem
im = imread('data/annie.jpg');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
options.debug = 0;

% compute all of the data output

bw = [10,10]; %first is colors, 2nd is space
[pts_10_10,clusters_10_10] = meanShiftSegment2(data,"G",bw,options);
pts_10_10  = lab2rgb(pts_10_10);

bw = [10,25]; %first is colors, 2nd is space
[pts_25_10,clusters_25_10] = meanShiftSegment2(data,"G",bw,options);
pts_25_10  = lab2rgb(pts_25_10);

% figure;
% subplot(1,3,1)
% imshow(im);
% title('Original');
% subplot(1,3,2)
% imshow(pts_10_10);
% title('(hs,hr) = (10,10)');
% subplot(1,3,3)
% imshow(pts_25_10);
% title('(hs,hr) = (25,10)');

bw = [10,50]; %first is colors, 2nd is space
[pts_50_10,clusters_50_10] = meanShiftSegment2(data,"G",bw,options);
pts_50_10  = lab2rgb(pts_50_10);

bw = [5,25]; %first is colors, 2nd is space
[pts_25_5,clusters_25_5] = meanShiftSegment2(data,"G",bw,options);
pts_25_5  = lab2rgb(pts_25_5);

bw = [5,50]; %first is colors, 2nd is space
[pts_50_5,clusters_50_5] = meanShiftSegment2(data,"G",bw,options);
pts_50_5  = lab2rgb(pts_50_5);

bw = [25,10]; %first is colors, 2nd is space
[pts_10_25,clusters_10_25] = meanShiftSegment2(data,"G",bw,options);
pts_10_25  = lab2rgb(pts_10_25);

bw = [25,25]; %first is colors, 2nd is space
[pts_25_25,clusters_25_25] = meanShiftSegment2(data,"G",bw,options);
pts_25_25  = lab2rgb(pts_25_25);

bw = [25,50]; %first is colors, 2nd is space
[pts_50_25,clusters_50_25] = meanShiftSegment2(data,"G",bw,options);
pts_50_25  = lab2rgb(pts_50_25);

% plot the final image
figure
subplot(3,3,1)
imshow(im);
title('Original');
subplot(3,3,2)
imshow(pts_10_10);
title('(hs,hr) = (10,10)');
subplot(3,3,3)
imshow(pts_10_25);
title('(hs,hr) = (10,25)');
subplot(3,3,4)
imshow(pts_25_5);
title('(hs,hr) = (25,5)');
subplot(3,3,5)
imshow(pts_25_10);
title('(hs,hr) = (25,10)');
subplot(3,3,6)
imshow(pts_25_25);
title('(hs,hr) = (25,25)');
subplot(3,3,7)
imshow(pts_50_5);
title('(hs,hr) = (50,5)');
subplot(3,3,8)
imshow(pts_50_10);
title('(hs,hr) = (50,10)');
subplot(3,3,9)
imshow(pts_50_25);
title('(hs,hr) = (50,25)');