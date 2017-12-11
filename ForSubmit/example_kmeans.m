clear;
im = imread('data/LakeCastle2.jpg');
lab = rgb2lab(im);
% add in XY coords
[X,Y] = meshgrid(1:size(im,2),1:size(im,1));
data = cat(3,lab,X,Y);
% compute the mean shift as normal
options.debug = 1;
options.mode = 'M';
bw = [8,8,20];
[pts_out,xy_out,~,~,~] = meanShiftSegmentFinal(data,bw,options);
showing the failure of kmeans
[idx,C] = kmeans(reshape(cat(3,pts_out,xy_out),size(X,1)*size(X,2),[]),200);
kclusters = C(idx,:);
kclusters = reshape(kclusters,size(X,1),size(X,2),[]);
subplot(1,3,1);
imshow(im)
subplot(1,3,2);
imshow(lab2rgb(pts_out));
subplot(1,3,3);
imshow(lab2rgb(kclusters(:,:,1:3)));