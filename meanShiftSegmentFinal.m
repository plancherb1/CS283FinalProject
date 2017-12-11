function [pts_out,xy_out,cluster_sizes,clusters,clustersXY] = meanShiftSegmentFinal(X,bandwidth,options)
% Compute the mean shift procedure on the input data and return the clustered output
%
% Adapted from:
% Comaniciu and Meer. "Mean Shift: A Robust Approach Toward Feature Space
% Analysis" IEE Transactions on Pattern Analysis and Machine Intelligence.
% Vol. 24, No. 5, May 2002.
    % parameters
    if nargin < 3
        error('Invlaid usage: pts, bandwidth=(color,space,clusterSize), [options]');
    elseif nargin == 2
        options = {};
    end
    if ~isfield(options,'tolExit')
        options.tolExit = 1;
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
    if ~isfield(options,'mode')
        options.mode = 'A';
    end
    if ~isfield(options,'crand')
        options.crand = 0;
    end
    if ~isfield(options,'smooth')
        options.smooth = 0;
    end
    if ~isfield(options,'smoothLevel')
        options.smoothLevel = 0.1;
    end
    if ~isfield(options,'cs')
        options.cs = 0;
    end
    
    % check the mode
    if options.mode == 'A'
        disp('Computing everything')
    elseif options.mode == 'M'
        disp('Computing mean shift only -- clusters will be empty list');
    elseif options.mode == 'C'
        disp('Computing clusters only -- assuming X are already shifted')
    else
        disp('Valid modes are [A]ll (default), [M]ean shift only, [C]usters only');
    end
    
    % define Kernel functions
    l = size(X,1);
    w = size(X,2);
    features = size(X,3);
    if options.kernel == "G" % Gausian
        % 2*sigma^2 = bandwidth^2
        sigma_r = bandwidth(1)/sqrt(2);
        sigma_s = bandwidth(2)/sqrt(2);
        mGr = 1/(2*sigma_r^features);%(1/(2*pi*sigma_r^2))^(1/2);
        mGs = 1/(2*sigma_s^2);%(1/(2*pi*sigma_s^2))^(1/2);
        kernel = @(D)(mGr.*exp(-(D)/(2*sigma_r^2)));
        % if we use a fixed support we can pre-compute the distance weightings
        % use an odd-size square window with length greater than 5 times sigma
        wGxy = 2*floor(ceil(7*sigma_s)/2)+1;
        [xx,yy]=meshgrid(-(wGxy-1)/2:(wGxy-1)/2,-(wGxy-1)/2:(wGxy-1)/2);
        Gxy = mGs.*exp(-(xx.^2+yy.^2)/(2*sigma_s^2));
    elseif options.kernel == 'U' % Uniform
        kernel = @(D)(D<bandwidth(1)^2);
        % again we can use a fixed size window
        wGxy = floor(bandwidth(2)/2)*2+1;
        Gxy = ones(wGxy,wGxy);
    else
        error("Invalid Kernel Type: options are [G]ausian (default), [U]niform")
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % first compute the mean shift %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % loop until done shifting if requested
    if ~(options.mode == 'C')
        if options.debug
            tic
        end
        [currX,shiftData] = meanShift(X,Gxy,kernel,options);    
        if options.debug
            t = toc;
            disp(['Total mean shift time: ', num2str(t), ' maxShifts: ', num2str(max(shiftData(:))), ...
                  ' medianShifts: ', num2str(median(shiftData(:))),' meanShifts: ', num2str(mean(shiftData(:)))]);
        end
    else
        currX = X;
    end
    % format the output points
    pts_out = currX(:,:,1:end-2);
    xy_out = currX(:,:,end-1:end);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %  perform clustering on that  %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % preform clustering is requested
    if ~(options.mode == 'M')
        if options.debug
            tic
        end
        if options.cs
            cluster_sizes = options.cs;
        elseif options.crand
            cluster_sizes = rand(l,w)*400; 
        else
            [cluster_sizes] = computeClusterSizes(currX,bandwidth(1),max(size(Gxy)));
        end
        [clusters,clustersXY] = computeClusters(currX,cluster_sizes,bandwidth,max(size(Gxy)),options);
        if options.debug
            t = toc;
            disp(['Clustering Time: ', num2str(t)]);
        end
    else
        clusters = [];
        clustersXY = [];
        cluster_sizes = [];
    end
end

function [newX,shiftData] = meanShift(X,Gxy,kernel,options)
% given the original data X of size l by w by features where
% the last two features are (x,y) position and a spatial
% filter Gxy and a feature kernel and options compute
% the mean shift for each point and return it
    l = size(X,1);
    w = size(X,2);
    shiftData = zeros(l,w);
    deltaXY = (size(Gxy,1)-1)/2;
    % loop for now because vectored is too big
    currX = X;
    newX = currX;
    for i=1:l
        for j=1:w
            % we can note that because of fixed support we only care
            % about points within distance bandwith of the point and
            % can then compute the kernel for the color impact
            % we assume zero padding on the borders so compute the 
            % various things we need to multiply and index with
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
            % now that we have the boundaries shift the point until
            % convergence to a local max (with perturbations to test
            % for saddle points)
            prevFinal = currX(i,j,:);
            for shifts=1:options.maxLoops
                % get the distance in the color space
                D1 = sum((X(startY:endY,startX:endX,1:end-2)-currX(i,j,1:end-2)).^2,3);
                % then compute the kernel of D (including /bandwidth)
                K1 = kernel(D1);
                K2 = Gxy(Gsy:Gey,Gsx:Gex);
                K = K1.*K2;
                % then compute the vectorized mean shift
                currX(i,j,:) = sum(sum(X(startY:endY,startX:endX,:).*K,1),2)/sum(K(:));
                % then check to see if we are converged
                delta = sum((currX(i,j,:)-newX(i,j,:)).^2,3);
                newX(i,j,:) = currX(i,j,:);
                if delta < options.tolExit
                    % if converged check to make sure we are at a local max
                    % by perturbing and only exiting if we have reached the
                    % same max twice
                    if sum((prevFinal - newX(i,j,:)).^2,3) < options.tolExit
                        shiftData(i,j) = shifts;
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

function [cluster_sizes] = computeClusterSizes(currX,bandwidthLAB,sizeXY)
% given the shifted data currX of size l by w by features where
% the last two features are (x,y) position find the basin of attraction
% for all points as determined by the bandwidth
    scale = 1;
    sizeXY = scale*sizeXY;
    l = size(currX,1);
    w = size(currX,2);
    cluster_sizes = zeros(l,w);
    for r=1:l
        for c=1:w
            startY = max(r-sizeXY,1);
            endY = min(r+sizeXY,l);
            startX = max(c-sizeXY,1);
            endX = min(c+sizeXY,w);
            valid = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) < bandwidthLAB.^2;
            cluster_sizes(r,c) = nnz(valid);
        end
    end
end

function [clusters,clustersXY] = computeClusters(currX,cluster_sizes,bandwidth,sizeXY,options)
% given the shifted data currX of size l by w by features where
% the last two features are (x,y) position and given the size of the
% basin of attraction find the final clusters
    M = bandwidth(3);
    l = size(currX,1);
    w = size(currX,2);
    cluster_labels = zeros(l,w);
    label_to_point = [];
    cluster_sizes = cluster_sizes.*(cluster_sizes>M);
    done = 0;
    curr_label = 1;
    while ~done
        % find the heuristically largest cluster center left
        % and compute the window for that part of the state space
        [~,idx] = max(cluster_sizes(:));
        [r,c] = ind2sub([l,w],idx(1));
        currPt = currX(r,c,:);
        cluster_sizes(r,c) = 0;
        startY = max(r-sizeXY,1);
        endY = min(r+sizeXY,l);
        startX = max(c-sizeXY,1);
        endX = min(c+sizeXY,w);
        currWindow = currX(startY:endY,startX:endX,:);
        % then find all of the points that fall in that basin of attraction
        valid = sum((currWindow(:,:,1:end-2) - currPt(:,:,1:end-2)).^2,3) < bandwidth(1)^2;
        % and figure out which points where already assigned
        overlap = valid.*cluster_labels(startY:endY,startX:endX);
        overlap_labels = unique(overlap);
        overlap = overlap > 0;
        overlap_labels = overlap_labels(any(overlap_labels ~= 0,2),:);
        overlapCount = size(overlap_labels,1);
        % only place new clusters bigger than M pixels
        if nnz(valid) > M
            if overlapCount
                % if it overlaps with only one cluster than assign it to that cluster
                if overlapCount == 1
                    pt_label = overlap_labels(1);
                % else we need to potentially merge clusters
                else
                    % first we get the values of the merge candidates
                    merge_candidates = label_to_point(overlap_labels,:);
                    % and we compute the size of each cluster
                    size_f = @(index)(nnz(cluster_labels == overlap_labels(index)));
                    merge_candidates_sizes = arrayfun(size_f,1:length(overlap_labels));
                    % we need to compute the pairwise distances between the
                    % various clusters to see if they attract each other - we
                    % only compare the colors as this process is being done
                    % with the spatial restrictions already put in place by the
                    % windowing done to select these -- we can use pdist
                    % because in this case we have a small set to compare
                    mergeable = squareform(pdist(merge_candidates(:,1:3))) < bandwidth(1);
                    if nnz(mergeable)
                        weights = mergeable .* reshape(merge_candidates_sizes,1,[]);
                        % we then base off of the largest current cluster and
                        % update all of it's pairs and then descend until all that
                        % can be merged are by merging with a weighted average of
                        % the colors and space values for those areas.
                        [~,order] = sort(merge_candidates_sizes,'descend');
                        updated = zeros(overlapCount,1);
                        for loop=1:overlapCount
                            idx = order(loop);
                            ws = weights(idx,:);
                            val = ws*merge_candidates./sum(ws);
                            for posIdx=1:length(ws)
                                if ws(posIdx) > 0 && updated(posIdx) == 0
                                    label_to_point(overlap_labels(posIdx),:) = val;
                                    updated(posIdx) = 1;
                                end
                            end
                            if nnz(updated) == 0
                                break
                            end
                        end
                    end
                    merge_candidates_sizes = arrayfun(size_f,1:length(overlap_labels));
                    [~,idx] = max(merge_candidates_sizes);
                    pt_label = overlap_labels(idx);
                end
            % otherwise we have found a new cluster so assign it accordingly
            else
                pt_label = curr_label;
                label_to_point(pt_label,:) = reshape(currPt,1,[]);
                curr_label = curr_label + 1;
            end
            % save the appropriate values
            cluster_labels(startY:endY,startX:endX,:) = cluster_labels(startY:endY,startX:endX,:) + (valid-overlap).*pt_label;
            cluster_sizes(startY:endY,startX:endX,:) = cluster_sizes(startY:endY,startX:endX,:).*(~valid);
            done = nnz(cluster_sizes) == 0;
        end
    end
    cluster_labels(find(cluster_labels == 0)) = NaN;
    cluster_labels = fillmissing(cluster_labels,'nearest');
    % then smooth output if requested
    if options.smooth
        % find all of the clusters and sort them by size
        uniqueC = unique(cluster_labels);
        size_f = @(index)(nnz(cluster_labels == uniqueC(index)));
        clusterS = arrayfun(size_f,1:length(uniqueC));
        [~,orderS] = sort(clusterS,'ascend');
        % smooth out all of the small clusters to get rid of any patchy
        % ones (if a large cluster is a problem smoothing it will take over
        % the entire picture in this manner so it is skipped) but the user
        % can pick this with options.smoothLevel
        total = sum(clusterS < options.smoothLevel*sum(clusterS));
        % smooth with less than the bandwidh used before to not do too much
        SE = strel('disk',bandwidth(2)/3,8);
        for idx=1:total
            curr_c = orderS(idx);
            newLabels = imclose(cluster_labels == uniqueC(curr_c),SE);
            cluster_labels = cluster_labels.*~newLabels + uniqueC(curr_c).*newLabels;
        end
    end
    % finally create the final cluster values from the labels
    cluster_labels = reshape(cluster_labels,l*w,1);
    clusters = label_to_point(cluster_labels,:);
    clusters = reshape(clusters,l,w,[]);
    clustersXY = clusters(:,:,end-1:end);
    clusters = clusters(:,:,1:end-2);
end