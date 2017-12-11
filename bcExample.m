clear;
load('bc2.mat');
% im = imread('data/bc2.jpg');
% lab = rgb2lab(im);
% % add in XY coords
% [X,Y] = meshgrid(1:size(lab,2),1:size(lab,1));
% data = cat(3,lab,X,Y);
% bw = [8,8,50];
% options.debug = 1;
% options.mode = 'M';
% [pts_out,xy_out,~] = meanShiftSegment6(data,bw,options);
% msPts = cat(3,pts_out,xy_out);
% tic
% cs = zeros(size(msPts,1),size(msPts,2),size(msPts,3)-2);
% for r=1:size(msPts,1)
%     for c=1:size(msPts,2)
%         valid = sum((msPts(:,:,1:end-2) - msPts(r,c,1:end-2)).^2,3) < bandwidth(1).^2;
%         cs(r,c) = nnz(valid);
%     end
% end
% toc
% tic
% cs2 = zeros(size(msPts,1),size(msPts,2),size(msPts,3)-2);
% MdlKDT = KDTreeSearcher(reshape(msPts(:,:,1:end-2),size(msPts,1)*size(msPts,2),[]));
% toc
% tic
% for r=1:size(msPts,1)
%     for c=1:size(msPts,2)
%         idx = rangesearch(MdlKDT,reshape(msPts(r,c,1:end-2),1,[]),bandwidth(1));
%         cs2(r,c) = length(idx{1});
%     end
% end
% toc
% tic
% sizes = computeClusterSizes(msPts,bw);
% toc
% tic
% sizes2 = computeClusterSizes2(msPts,bw);
% toc
% tic
% sizes3 = computeClusterSizes3(msPts,bw);
% toc

% bw = [8,8,20];
% testGlob = msPts;%(50:200,400:550,:);
% tic
% sizes4 = computeClusterSizes4(testGlob,bw);
% toc
% tic
% [clusters] = computeClusters(testGlob,sizes4,bw);
% toc
% 
% figure
% subplot(1,2,1)
% imshow(lab2rgb(msPts(:,:,1:3)))
% subplot(1,2,2)
% imshow(lab2rgb(clusters))


% testGlob = msPts(50:200,400:550,:);
% testl = size(testGlob,1);
% testw = size(testGlob,2);
% maxColor = 255;
bw = [8,8,20];
options.mode = 'C';
[~,~,~,clusters,clustersXY] = meanShiftSegment7(msPts,bw,options);
% [~,~,~,clusters2,clusters2XY] = meanShiftSegment6(cat(3,clusters,clustersXY),bw,options);
% [~,~,~,clusters3,clusters3XY] = meanShiftSegment6(cat(3,clusters2,clusters2XY),bw,options);
figure;
subplot(1,2,1);
imshow(im);
% subplot(1,3,2);
% imshow(lab2rgb(msPts(:,:,1:3)));
subplot(1,2,2);
imshow(lab2rgb(clusters(:,:,1:3)));
% subplot(2,2,3);
% imshow(lab2rgb(clusters2(:,:,1:3)));
% subplot(2,2,4);
% imshow(lab2rgb(clusters3(:,:,1:3)));
disp('hi');

% lspace = 1:floor(testl / bw(2)):testl;
% if ~(lspace(end) == testl)
%     lspace = [lspace,testl];
% end
% wspace = 1:floor(testw / bw(2)):testw;
% if ~(wspace(end) == testw)
%     wspace = [wspace,testw];
% end
% rspace = 1:floor(maxColor / bw(1)):maxColor;
% if ~(rspace(end) == maxColor)
%     rspace = [rspace,maxColor];
% end
% clusters = zeros(testl,testw,size(testGlob,3));
% for i1=1:testl
%     for i2=1:testw
%         [~,iL] = min(abs(testGlob(i1,i2,end-1)-lspace));
%         [~,iW] = min(abs(testGlob(i1,i2,end-1)-wspace));
%         vals
%         for i3=1:(size(testGlob,3)-1)
%             [~,iR] = min(abs(testGlob(i1,i2,end-1)-rspace));
%         end
%     end
% end

% [clusterId,means] = kmeans(reshape(testGlob,testl*testw,[]),50);
% clusterId = reshape(clusterId,testl,testw,[]);
% clusters = zeros(testl,testw,size(testGlob,3)-2);
% for i1=1:testl
%     for i2=1:testw
%         clusters(i1,i2,:) = means(clusterId(i1,i2),1:3);
%     end
% end
% imshow(lab2rgb(clusters(:,:,1:3)))

options.mode = 'C';
[~,~,clusterId] = meanShiftSegment6(msPts,bw,options);

figure;
subplot(1,3,1);
imshow(im);
title('Original Image');
subplot(1,3,2);
imshow(lab2rgb(pts_out));
title(['(hs,hr) = (',num2str(bw(2)),',',num2str(bw(1)),')']);
subplot(1,3,3);
imshow(lab2rgb(clusterId));
title('(hs,hr,M) = (8,16,50)');

function [cluster_sizes] = computeClusterSizes(currX,bandwidth)
    l = size(currX,1);
    w = size(currX,2);
    cluster_sizes = zeros(l,w);
    seeds = zeros(l,w);
    seeds(floor(bandwidth(2)/2):bandwidth(2):end,floor(bandwidth(2)/2):bandwidth(2):end) = 1;
    while nnz(seeds)
        [r,c] = find(seeds,1);
        seeds(r,c) = 0;
        startY = max(r-bandwidth(2),1);
        endY = min(r+bandwidth(2),l);
        startX = max(c-bandwidth(2),1);
        endX = min(c+bandwidth(2),w);
        section = currX(startY:endY,startX:endX,1:end-2);
        idx = rangesearch(reshape(section,size(section,1)*size(section,2),[]),reshape(currX(r,c,1:end-2),1,[]),bandwidth(1));
        cluster_sizes(r,c) = length(idx{1});
    end
end

function [cluster_sizes] = computeClusterSizes2(currX,bandwidth)
    l = size(currX,1);
    w = size(currX,2);
    cluster_sizes = zeros(l,w);
    for r=floor(bandwidth(2)/2):bandwidth(2):l
        for c=floor(bandwidth(2)/2):bandwidth(2):w
            startY = max(r-bandwidth(2),1);
            endY = min(r+bandwidth(2),l);
            startX = max(c-bandwidth(2),1);
            endX = min(c+bandwidth(2),w);
            section = currX(startY:endY,startX:endX,1:end-2);
            idx = rangesearch(reshape(section,size(section,1)*size(section,2),[]),reshape(currX(r,c,1:end-2),1,[]),bandwidth(1));
            cluster_sizes(r,c) = length(idx{1});
        end
    end
end

function [cluster_sizes] = computeClusterSizes3(currX,bandwidth)
    l = size(currX,1);
    w = size(currX,2);
    cluster_sizes = zeros(l,w);
    for r=floor(bandwidth(2)/2):bandwidth(2):l
        for c=floor(bandwidth(2)/2):bandwidth(2):w
            startY = max(r-bandwidth(2),1);
            endY = min(r+bandwidth(2),l);
            startX = max(c-bandwidth(2),1);
            endX = min(c+bandwidth(2),w);
            section = currX(startY:endY,startX:endX,1:end-2);
            valid = sum((section - currX(r,c,1:end-2)).^2,3) < bandwidth(1).^2;
            cluster_sizes(r,c) = nnz(valid);
        end
    end
end

function [cluster_sizes] = computeClusterSizes4(currX,bandwidth)
    l = size(currX,1);
    w = size(currX,2);
    cluster_sizes = zeros(l,w);
    for r=1:l
        for c=1:w
            startY = max(r-bandwidth(2),1);
            endY = min(r+bandwidth(2),l);
            startX = max(c-bandwidth(2),1);
            endX = min(c+bandwidth(2),w);
            valid = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) < bandwidth(1).^2;
            cluster_sizes(r,c) = nnz(valid);
        end
    end
end

function [clusters] = computeClusters(currX,cluster_sizes,bandwidth)
    l = size(currX,1);
    w = size(currX,2);
    clusters = zeros(l,w,size(currX,3)-2);
    cluster_sizes = cluster_sizes.*(cluster_sizes>bandwidth(3));
    done = 0;
    while ~done
        [~,idx] = max(cluster_sizes(:));
        [r,c] = ind2sub([l,w],idx(1));
        cluster_sizes(r,c) = 0;
        startY = max(r-bandwidth(2),1);
        endY = min(r+bandwidth(2),l);
        startX = max(c-bandwidth(2),1);
        endX = min(c+bandwidth(2),w);
        valid = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) < bandwidth(1)^2;
        valid = valid.*(clusters(startY:endY,startX:endX) == 0);
        if nnz(valid) > bandwidth(3)
            clusters(startY:endY,startX:endX,:) = clusters(startY:endY,startX:endX,:) + valid.*currX(startY:endY,startX:endX,1:end-2);
            cluster_sizes(startY:endY,startX:endX,:) = cluster_sizes(startY:endY,startX:endX,:).*(~valid);
        end
        done = nnz(cluster_sizes) == 0;
    end
    clusters(find(clusters == 0)) = NaN;
    clusters = fillmissing(clusters,'nearest');
end