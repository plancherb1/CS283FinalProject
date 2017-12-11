function [pts_out,clusters] = meanShiftSegment3(X,bandwidth,options)
% Compute the mean shift procedure on the input data and return the segmented data labels
%
% Adapted from:
% Comaniciu and Meer. "Mean Shift: A Robust Approach Toward Feature Space
% Analysis" IEE Transactions on Pattern Analysis and Machine Intelligence.
% Vol. 24, No. 5, May 2002.
    % parameters
    if nargin < 3
        error("Invlaid usage: pts, kernel_type, bandwidth, [options]");
    elseif nargin == 2
        options = {};
    end
    if ~isfield(options,'tolExit')
        options.tolExit = 1e-1;
    end
    if ~isfield(options,'tolCluster')
        options.tolCluster = 10;
    end 
    if ~isfield(options,'maxLoops')
        options.maxLoops = 100;
    end 
    if ~isfield(options,'debug')
        options.debug = 0;
    end 

    % if we use a fixed support we can pre-compute the distance weightings
    % use an odd-size square window with length greater than 5 times sigma
    % noting that bandwidth is therefore w so solving backward to get sigma
    % from bandwidth where w=2*floor(ceil(7*sigma)/2)+1;
    wGxy = floor(bandwidth(2)/2)*2+1;
    sigma = ceil((wGxy-1)/2)*2/7;
    [xx,yy]=meshgrid(-(wGxy-1)/2:(wGxy-1)/2,-(wGxy-1)/2:(wGxy-1)/2);
    Gxy = 1/(2*pi*sigma^2)*exp(-(xx.^2+yy.^2)/(2*sigma^2));
    
    % local vars
    l = size(X,1);
    w = size(X,2);
    currX = X;
    activeIndicies = ones(l,w);
    
    % loop until done shifting
    for i=1:options.maxLoops
        
        % use mean shift on the points
        tic
        [newX] = meanShiftLABXY(X,currX,activeIndicies,bandwidth(1),Gxy,(wGxy-1)/2);
        t = toc;
        
        % see how many indicies are still active and update
        delta = sum((currX-newX).^2,3);
        activeIndicies = delta > options.tolExit;
        
        % display stats on iter
        countActive = nnz(activeIndicies);
        if options.debug
            disp(['[',num2str(i),'] countActive: ',num2str(countActive),' time: ',num2str(t)]);
        end
        
        % update variables
        currX = newX;
        
        % exit if done
        if(countActive == 0)
            break;
        end
    end
%     pts_out = reshape(currX(1:3,:)',l,w,[]);
    pts_out = currX(:,:,1:end-2);
    
    % now find the clusters in X (means that shifted to within tol)
    clusters = pts_out;
%     curr_cluster = 1;
%     clusters = zeros(1,l*w);
%     guess = 1;
%     while size(guess,2)
%         try
%             test = sum((currX(1:3,:) - currX(1:3,guess)).^2,1) < options.tolCluster;
%         catch
%             disp(':(');
%         end
%         clusters(find(test)) = curr_cluster;
%         curr_cluster = curr_cluster + 1;
%         guess = find(clusters == 0,1);
%     end
%     clusters = reshape(clusters,l,w);
end

function [newX] = meanShiftLABXY(X,currX,activeIndicies,bandwidthLAB,Gxy,deltaXY)
    mG = (1/(2*pi))^(1/2);
    % loop for now because vectored is too big
    newX = currX;
    for i=1:size(X,1)
        for j=1:size(X,2)
            if activeIndicies(i,j)
                % we can note that because of fixed support we only care
                % about points within distance bandwith of the point and
                % can then compute the kernel for the color impact
                % we assume zero padding on the borders
                ieff = floor(currX(i,j,end));
                jeff = floor(currX(i,j,end-1));
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
                D1 = sum((X(startY:endY,startX:endX,1:end-2)-currX(i,j,1:end-2)).^2,3)./bandwidthLAB;
                % then compute the kernel of D (including /bandwidth)
                K1 = mG.*exp(-1/2.*(D1));
                K1 = K1./sum(K1(:));
                K2 = Gxy(Gsy:Gey,Gsx:Gex);
                K2 = K2./sum(K2(:));
                K = K1.*K2;
                K = K./sum(K(:));
                % then compute the vectorized mean shift
                newX(i,j,:) = sum(sum(X(startY:endY,startX:endX,:).*K,1),2)/sum(K(:));
            end
        end
    end
end