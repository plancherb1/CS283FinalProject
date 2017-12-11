clear;
% setup the problem
im = imread('data/baboon.tif');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
data = cat(3,lab,X,Y);
options.debug = 0;
options.mode = 'M';

% compute all of the data output

bw = [8,8,20]; %first is colors, 2nd is space
[pts_8_8,~,~,~] = meanShiftSegment6(data,bw,options);
pts_8_8  = lab2rgb(pts_8_8);
disp('done with 8_8');

bw = [8,16,20]; %first is colors, 2nd is space
[pts_16_8,~,~,~] = meanShiftSegment6(data,bw,options);
pts_16_8  = lab2rgb(pts_16_8);
disp('done with 16_8');

bw = [8,32,20]; %first is colors, 2nd is space
[pts_32_8,~,~,~] = meanShiftSegment6(data,bw,options);
pts_32_8  = lab2rgb(pts_32_8);
disp('done with 32_8');

bw = [4,16,20]; %first is colors, 2nd is space
[pts_16_4,~,~,~] = meanShiftSegment6(data,bw,options);
pts_16_4  = lab2rgb(pts_16_4);
disp('done with 16_4');

bw = [4,32,20]; %first is colors, 2nd is space
[pts_32_4,~,~,~] = meanShiftSegment6(data,bw,options);
pts_32_4  = lab2rgb(pts_32_4);
disp('done with 32_4');

bw = [16,8,20]; %first is colors, 2nd is space
[pts_8_16,~,~,~] = meanShiftSegment6(data,bw,options);
pts_8_16  = lab2rgb(pts_8_16);
disp('done with 8_16');

bw = [16,16,20]; %first is colors, 2nd is space
[pts_16_16,~,~,~] = meanShiftSegment6(data,bw,options);
pts_16_16  = lab2rgb(pts_16_16);
disp('done with 16_16');

bw = [16,32,20]; %first is colors, 2nd is space
[pts_32_16,~,~,~] = meanShiftSegment6(data,bw,options);
pts_32_16  = lab2rgb(pts_32_16);
disp('done with 32_16');

% plot the final image
figure
subplot(3,3,1)
imshow(im);
title('Original');
subplot(3,3,2)
imshow(pts_8_8);
title('(hs,hr) = (8,8)');
subplot(3,3,3)
imshow(pts_8_16);
title('(hs,hr) = (8,16)');
subplot(3,3,4)
imshow(pts_16_4);
title('(hs,hr) = (16,4)');
subplot(3,3,5)
imshow(pts_16_8);
title('(hs,hr) = (16,8)');
subplot(3,3,6)
imshow(pts_16_16);
title('(hs,hr) = (16,16)');
subplot(3,3,7)
imshow(pts_32_4);
title('(hs,hr) = (32,4)');
subplot(3,3,8)
imshow(pts_32_8);
title('(hs,hr) = (32,8)');
subplot(3,3,9)
imshow(pts_32_16);
title('(hs,hr) = (32,16)');