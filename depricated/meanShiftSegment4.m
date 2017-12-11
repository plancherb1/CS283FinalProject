function [pts_out,clusters] = meanShiftSegment4(X,bandwidth,options)
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
    if ~isfield(options,'maxLoops')
        options.maxLoops = 100;
    end 
    if ~isfield(options,'debug')
        options.debug = 0;
    end 
    if ~isfield(options,'kernel')
        options.kernel = 'G';
    end
    if ~isfield(options,'cluster')
        options.kernel = 'Y';
    end

    % define Kernel functions
    mG = (1/(2*pi))^(1/2);
    if options.kernel == "G" % Gausian
        kernel = @(D)(mG.*exp(-1/2.*(D)));
        % if we use a fixed support we can pre-compute the distance weightings
        % use an odd-size square window with length greater than 5 times sigma
        % noting that bandwidth is therefore w so solving backward to get sigma
        % from bandwidth where w=2*floor(ceil(7*sigma)/2)+1;
        wGxy = floor(bandwidth(2)/2)*2+1;
        sigma = ceil((wGxy-1)/2)*2/7;
        [xx,yy]=meshgrid(-(wGxy-1)/2:(wGxy-1)/2,-(wGxy-1)/2:(wGxy-1)/2);
        Gxy = 1/(2*pi*sigma^2)*exp(-(xx.^2+yy.^2)/(2*sigma^2));
    elseif options.kernel == 'U' % Uniform
        kernel = @(D)((D<bandwidth(1)));
        % again we can use a fixed size window
        wGxy = floor(bandwidth(2)/2)*2+1;
        Gxy = ones(wGxy,wGxy);
    else
        error("Invalid Kernel Type: options are [G]ausian, [U]niform")
    end
    
    % local vars
    l = size(X,1);
    w = size(X,2);
    currX = X;
    activeIndicies = ones(l,w);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % first compute the mean shift %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % loop until done shifting
    tic
    for i=1:options.maxLoops
        
        % use mean shift on the points
        if options.debug
            inner_tic = tic;
        end
        [newX] = meanShiftLABXY(X,currX,activeIndicies,bandwidth(1),Gxy,(wGxy-1)/2,kernel);
        if options.debug
            t = toc(inner_tic);
        end
        
        % see how many indicies are still active and update variables
        delta = sum((currX-newX).^2,3);
        activeIndicies = delta > options.tolExit;
        currX = newX;
        
        % find the active count
        countActive = nnz(activeIndicies);
        if options.debug
            disp(['[',num2str(i),'] countActive: ',num2str(countActive),' time: ',num2str(t)]);
        end
        
        % exit if done
        if(countActive == 0)
            break;
        end
    end
    if options.debug
        t = toc;
        disp(['Total mean shift time: ', num2str(t)]);
    end
    % format the output points
    pts_out = currX(:,:,1:end-2);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %  perform clustering on that  %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if ~(options.cluster == 'Y')
        clusters = pts_out;
        return;
    end
    
    % first find where the bigest clusters are
    if options.debug
        tic
    end
    [cluster_sizes] = computeClusterSizes(currX,bandwidth);
    if options.debug
        t = toc;
        disp(['Cluster Size Time: ', num2str(t)]);
    end
    % now clusters from big to small and any cluster under size M make sure
    % to make it equal to the average value of its border
    if options.debug
        tic
    end
    [clusters] = computeClusters(currX,bandwidth,cluster_sizes,bandwidth(3));
    if options.debug
        t = toc;
        disp(['Clustering Time: ', num2str(t)]);
    end
end

function [newX] = meanShiftLABXY(X,currX,activeIndicies,bandwidthLAB,Gxy,deltaXY,kernel)
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
                K1 = kernel(D1);
                K1 = K1./sum(K1(:));
                K2 = Gxy(Gsy:Gey,Gsx:Gex);
                K2 = K2./sum(K2(:));
                K = K1.*K2;
%                 K = K./sum(K(:));
                % then compute the vectorized mean shift
                newX(i,j,:) = sum(sum(X(startY:endY,startX:endX,:).*K,1),2)/sum(K(:));
            end
        end
    end
end

function [cluster_sizes] = computeClusterSizes(currX,bandwidth)
    l = size(currX,1);
    w = size(currX,2);
    cluster_sizes = zeros(l,w);
    % loop through all points to compute cluster sizes around those points
    for r=1:l
        startY = max(r-bandwidth(2),1);
        endY = min(r+bandwidth(2),l);
        for c=1:w
            startX = max(c-bandwidth(2),1);
            endX = min(c+bandwidth(2),w);
            % see in the window how many points it pulls with it
            color = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) <= bandwidth(1).^2;
            distance = sum((currX(startY:endY,startX:endX,end-1:end) - currX(r,c,end-1:end)).^2,3) <= bandwidth(2).^2;
            valid = color.*distance;
            cluster_sizes(r,c) = nnz(valid);
        end
    end
end

function [clusters] = computeClusters(currX,bandwidth,cluster_sizes,M)
    l = size(currX,1);
    w = size(currX,2);
    features = size(currX,3)-2;
    clusters = zeros(l,w,features);
    % loop until all clusters are assigned
    while nnz(cluster_sizes>0)
        % find the biggest cluster center left
        curr_max_size = max(cluster_sizes(:));
        [r,c] = find(curr_max_size == cluster_sizes,1);
        startY = max(r-bandwidth(2),1);
        endY = min(r+bandwidth(2),l);
        startX = max(c-bandwidth(2),1);
        endX = min(c+bandwidth(2),w);
        % find the points that support it in the window that are unassigned
        color = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) <= bandwidth(1).^2;
        distance = sum((currX(startY:endY,startX:endX,end-1:end) - currX(r,c,end-1:end)).^2,3) <= bandwidth(2).^2;
        valid = color.*distance.*(sum(clusters(startY:endY,startX:endX,:),3)==0);
        % find the values that remain
        rest = ~valid.*clusters(startY:endY,startX:endX,:);
        % if a large valid cluster assign all values to the cluster center and
        % remove all of those values from being a future cluster center
        if nnz(rest==0) > M
            clusters(startY:endY,startX:endX,:) = valid.*currX(r,c,1:end-2) + rest;
            cluster_sizes(startY:endY,startX:endX) = ~valid.*cluster_sizes(startY:endY,startX:endX);
        % else fill with the value from the nearest valid cluster
        else
            rest(rest==0) = NaN;
            clusters(startY:endY,startX:endX,:) = fillmissing(rest,'nearest');
            cluster_sizes(startY:endY,startX:endX) = 0;
        end
    end
end