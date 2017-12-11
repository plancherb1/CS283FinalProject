clear;
% read in the small image for testing and construct the data
im = imread('data/annie.jpg');
lab = rgb2lab(im);
[xx,yy] = meshgrid(1:size(lab,2),1:size(lab,1));
X = cat(3,lab,xx,yy);
currX = X;
bandwidth = [8,8,20];
options.tolExit = 1;
options.maxLoops = 100;

l = size(X,1);
w = size(X,2);
features = size(X,3);

Xrow = reshape(X,l*w,[]);
currXrow = Xrow;

% set up the kernel and distance functions
distance2 = @(X,x)(sum((X-x).^2,2));
distance3 = @(X,x)(sum((X-x).^2,3));
sigma_r = bandwidth(1)/sqrt(2);
sigma_s = bandwidth(2)/sqrt(2);
mGr = 1/(2*sigma_r^features);
mGs = 1/(2*sigma_s^2);
kernel_r = @(D)(mGr.*exp(-(D)/(2*sigma_r^2)));
kernel_s = @(D)(mGs.*exp(-(D)/(2*sigma_s^2)));
% if we use a fixed support we can pre-compute the distance weightings
% use an odd-size square window with length greater than 5 times sigma
wGxy = 2*floor(ceil(7*sigma_s)/2)+1;
[xx,yy]=meshgrid(-(wGxy-1)/2:(wGxy-1)/2,-(wGxy-1)/2:(wGxy-1)/2);
Gxy = mGs.*exp(-(xx.^2+yy.^2)/(2*sigma_s^2));

% then time the mean shift procedure for each type
% tic % too slow to be worth running -- I'm saving you hours lol
% [newX] = naive(Xrow,currXrow,kernel_r,kernel_s,distance2,options);
% t1 = toc

tic
[newX2] = parrallelPerPoint(Xrow,currXrow,kernel_r,kernel_s,distance2,options);
t2 = toc

tic
[newX3] = parrallelPerPointRS(Xrow,currXrow,kernel_r,kernel_s,distance2,wGxy,options);
t3 = toc

tic
[newX4] = windowedMS(X,Gxy,kernel_r,options);
t4 = toc

tic
[newX5] = windowedMSplusMode(X,Gxy,kernel_r,options);
t5 = toc

load('speedData')
d3 = reshape(newX3,l,w,[]) - reshape(newX2,l,w,[]);
d3 = (sum(d3(:,:,1:end-2).^2,3) < bandwidth(1)^2).* (sum(d3(:,:,end-1:end).^2,3) < bandwidth(2)^2);
a3 = nnz(d3) / (l*w)
d4 = newX4 - reshape(newX2,l,w,[]);
d4 = (sum(d4(:,:,1:end-2).^2,3) < bandwidth(1)^2).* (sum(d4(:,:,end-1:end).^2,3) < bandwidth(2)^2);
a4 = nnz(d4) / (l*w)
d5 = newX5 - newX4;
d5 = (sum(d5(:,:,1:end-2).^2,3) < bandwidth(1)^2).* (sum(d5(:,:,end-1:end).^2,3) < bandwidth(2)^2);
a5 = a4 ./ (nnz(d5) / (l*w))


disp('hi');

function [newX] = naive(X,currX,kernel_r,kernel_s,distance,options)
    newX = currX;
    for i=1:size(X,1)
        for shifts=1:options.maxLoops
            numer = zeros(1,size(X,2));
            denom = 0;
            for j=1:size(X,1)
                D1 = distance(X(j,1:end-2),currX(i,1:end-2));
                D2 = distance(X(j,end-1:end),currX(i,end-1:end));
                K1 = kernel_r(D1);
                K2 = kernel_s(D2);
                K = K1*K2;
                numer = numer + X(j,:)*K;
                denom = denom + K;
            end
            newX(i,:) = numer./denom;
            delta = sum((currX(i,:)-newX(i,:)).^2);
            if delta < options.tolExit
                break;
            else
                currX(i,:) = newX(i,:);
            end
        end
    end
end

function [newX] = parrallelPerPoint(X,currX,kernel_r,kernel_s,distance,options)
    newX = currX;
    for i=1:size(X,1)
        for shifts=1:options.maxLoops
            D1 = distance(X(:,1:end-2),currX(i,1:end-2));
            D2 = distance(X(:,end-1:end),currX(i,end-1:end));
            K1 = kernel_r(D1);
            K2 = kernel_s(D2);
            K = K1.*K2;
            newX(i,:) = sum(X.*K,1)/sum(K);
            delta = sum((currX(i,:)-newX(i,:)).^2);
            if delta < options.tolExit
                break;
            else
                currX(i,:) = newX(i,:);
            end
        end
    end
end

function [newX] = parrallelPerPointRS(X,currX,kernel_r,kernel_s,distance,gamma,options)
    XT = KDTreeSearcher(X(:,end-1:end));
    newX = currX;
    for i=1:size(X,1)
        for shifts=1:options.maxLoops
            Xprime = rangesearch(XT,currX(i,end-1:end),gamma);
            Xprime = X(Xprime{1},:);
            D1 = distance(Xprime(:,1:end-2),currX(i,1:end-2));
            D2 = distance(Xprime(:,end-1:end),currX(i,end-1:end));
            K1 = kernel_r(D1);
            K2 = kernel_s(D2);
            K = K1.*K2;
            newX(i,:) = sum(Xprime.*K,1)/sum(K);
            delta = sum((currX(i,:)-newX(i,:)).^2);
            if delta < options.tolExit
                break;
            else
                currX(i,:) = newX(i,:);
            end
        end
    end
end

function [newX] = windowedMS(X,Gxy,kernel,options)
    l = size(X,1);
    w = size(X,2);
    deltaXY = (size(Gxy,1)-1)/2;
    currX = X;
    newX = currX;
    for i=1:l
        for j=1:w
            ieff = round(currX(i,j,end));
            jeff = round(currX(i,j,end-1));
            startX = jeff-deltaXY;
            endX = jeff+deltaXY;
            Gsx = 1;
            Gex = deltaXY*2+1;
            if startX < 1
                Gsx = -1*startX+2;
                startX = 1;
            else
                if endX >= size(X,2)
                    Gex = Gex - (endX-size(X,2));
                    endX = size(X,2);
                end
            end
            startY = ieff-deltaXY;
            endY = ieff+deltaXY;
            Gsy = 1;
            Gey = deltaXY*2+1;
            if startY < 1
                Gsy = -1*startY+2;
                startY = 1;
            else
                if endY >= size(X,1)
                    Gey = Gey - (endY-size(X,1));
                    endY = size(X,1);
                end
            end
            for shifts=1:options.maxLoops
                D1 = sum((X(startY:endY,startX:endX,1:end-2)-currX(i,j,1:end-2)).^2,3);
                K1 = kernel(D1);
                K2 = Gxy(Gsy:Gey,Gsx:Gex);
                K = K1.*K2;
                currX(i,j,:) = sum(sum(X(startY:endY,startX:endX,:).*K,1),2)/sum(K(:));
                delta = sum((currX(i,j,:)-newX(i,j,:)).^2,3);
                newX(i,j,:) = currX(i,j,:);
                if delta < options.tolExit
                    break;
                end
            end
        end
    end
end

function [newX] = windowedMSplusMode(X,Gxy,kernel,options)
    l = size(X,1);
    w = size(X,2);
    deltaXY = (size(Gxy,1)-1)/2;
    currX = X;
    newX = currX;
    for i=1:l
        for j=1:w
            ieff = round(currX(i,j,end));
            jeff = round(currX(i,j,end-1));
            startX = jeff-deltaXY;
            endX = jeff+deltaXY;
            Gsx = 1;
            Gex = deltaXY*2+1;
            if startX < 1
                Gsx = -1*startX+2;
                startX = 1;
            else
                if endX >= size(X,2)
                    Gex = Gex - (endX-size(X,2));
                    endX = size(X,2);
                end
            end
            startY = ieff-deltaXY;
            endY = ieff+deltaXY;
            Gsy = 1;
            Gey = deltaXY*2+1;
            if startY < 1
                Gsy = -1*startY+2;
                startY = 1;
            else
                if endY >= size(X,1)
                    Gey = Gey - (endY-size(X,1));
                    endY = size(X,1);
                end
            end
            prevFinal = currX(i,j,:);
            for shifts=1:options.maxLoops
                D1 = sum((X(startY:endY,startX:endX,1:end-2)-currX(i,j,1:end-2)).^2,3);
                K1 = kernel(D1);
                K2 = Gxy(Gsy:Gey,Gsx:Gex);
                K = K1.*K2;
                currX(i,j,:) = sum(sum(X(startY:endY,startX:endX,:).*K,1),2)/sum(K(:));
                delta = sum((currX(i,j,:)-newX(i,j,:)).^2,3);
                newX(i,j,:) = currX(i,j,:);
                if delta < options.tolExit
                    if sum((prevFinal - newX(i,j,:)).^2,3) < options.tolExit
                        break;
                    else
                        prevFinal = newX(i,j,:);
                        newX(i,j,:) = newX(i,j,:) + rand(size(newX(i,j,:)));
                    end
                end
            end
        end
    end
end