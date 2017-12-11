function [pts_out,xy_out,cluster_sizes,clusters,clustersXY] = meanShiftSegment6(X,bandwidth,options)
% Compute the mean shift procedure on the input data and return the segmented data labels
%
% Adapted from:
% Comaniciu and Meer. "Mean Shift: A Robust Approach Toward Feature Space
% Analysis" IEE Transactions on Pattern Analysis and Machine Intelligence.
% Vol. 24, No. 5, May 2002.
    % parameters
    if nargin < 3
        error("Invlaid usage: pts, bandwidth=(color,space,clusterSize), [options]");
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
    
    % check the mode
    if options.mode == 'A'
        disp('Computing everything')
    elseif options.mode == 'M'
        disp('Computing mean shift only -- clusters will be empty list');
    elseif options.mode == 'C'
        disp('Computing clusters only -- assuming X are already shifted')
        options.maxLoops = 0;
    else
        disp('Valid modes are [A]ll (default), [M]ean shift only, [C]usters only');
    end

    % define Kernel functions
    mG = (1/(2*pi))^(1/2);
    if options.kernel == "G" % Gausian
        % 2*sigma^2 = bandwidth^2
        sigma_r = bandwidth(1)/sqrt(2);
        sigma_s = bandwidth(2)/sqrt(2);
        kernel = @(D)(mG.*exp(-(D)/(2*sigma_r^2)));
        % if we use a fixed support we can pre-compute the distance weightings
        % use an odd-size square window with length greater than 5 times sigma
        wGxy = 2*floor(ceil(7*sigma_s)/2)+1;
        [xx,yy]=meshgrid(-(wGxy-1)/2:(wGxy-1)/2,-(wGxy-1)/2:(wGxy-1)/2);
        Gxy = 1/(2*pi*sigma_s^2)*exp(-(xx.^2+yy.^2)/(2*sigma_s^2));
    elseif options.kernel == 'U' % Uniform
        kernel = @(D)(D<bandwidth(1)^2);
%         kernel = @(D)(D);
        % again we can use a fixed size window
        wGxy = floor(bandwidth(2)/2)*2+1;
        Gxy = ones(wGxy,wGxy);
    else
        error("Invalid Kernel Type: options are [G]ausian (default), [U]niform")
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
        [newX] = meanShiftLABXY(X,currX,activeIndicies,Gxy,kernel);
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
    xy_out = currX(:,:,end-1:end);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %  perform clustering on that  %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if options.debug
        tic
    end
    if (options.mode == 'M')
        clusters = [];
        cluster_sizes = [];
    else
        [cluster_sizes] = computeClusterSizes(currX,bandwidth(1),max(size(Gxy)));
        [clusters,clustersXY] = computeClusters(currX,cluster_sizes,bandwidth(1),max(size(Gxy)),bandwidth(3));
    end
    if options.debug
        t = toc;
        disp(['Clustering Time: ', num2str(t)]);
    end
end

function [newX] = meanShiftLABXY(X,currX,activeIndicies,Gxy,kernel)
    deltaXY = (size(Gxy,1)-1)/2;
    % loop for now because vectored is too big
    newX = currX;
    for i=1:size(X,1)
        for j=1:size(X,2)
            if activeIndicies(i,j)
                % we can note that because of fixed support we only care
                % about points within distance bandwith of the point and
                % can then compute the kernel for the color impact
                % we assume zero padding on the borders
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
                D1 = sum((X(startY:endY,startX:endX,1:end-2)-currX(i,j,1:end-2)).^2,3);
                % then compute the kernel of D (including /bandwidth)
                K1 = kernel(D1);
                K2 = Gxy(Gsy:Gey,Gsx:Gex);
                K = K1.*K2;
                % then compute the vectorized mean shift
                newX(i,j,:) = sum(sum(X(startY:endY,startX:endX,:).*K,1),2)/sum(K(:));
            end
        end
    end
end

function [cluster_sizes] = computeClusterSizes(currX,bandwidthLAB,sizeXY)
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

function [clusters,clustersXY] = computeClusters(currX,cluster_sizes,bandwidthLAB,sizeXY,M)
    l = size(currX,1);
    w = size(currX,2);
    features = size(currX,3);
    clusters = zeros(l,w,features);
    cluster_sizes = cluster_sizes.*(cluster_sizes>M);
    done = 0;
%     figure;
    while ~done
        [~,idx] = max(cluster_sizes(:));
        [r,c] = ind2sub([l,w],idx(1));
        currPt = currX(r,c,:);
        cluster_sizes(r,c) = 0;
        startY = max(r-sizeXY,1);
        endY = min(r+sizeXY,l);
        startX = max(c-sizeXY,1);
        endX = min(c+sizeXY,w);
        currWindow = currX(startY:endY,startX:endX,:);
        valid = sum((currWindow(:,:,1:end-2) - currPt(:,:,1:end-2)).^2,3) < bandwidthLAB^2;
        overlap_pts = valid.*clusters(startY:endY,startX:endX,:);
        overlap = sum(overlap_pts,3) > 0;
        overlap_pts = unique(reshape(overlap_pts,size(overlap_pts,1)*size(overlap_pts,2),[]),'rows');
        overlap_pts = overlap_pts(any(overlap_pts ~= 0,2),:);
        overlapCount = size(overlap_pts,1);
        if (nnz(valid) > M)
            if overlapCount
                if overlapCount > 1
                    cRows = reshape(clusters,l*w,[]);
                    maxo = 1;
                    maxoCount = 1;
                    for oindex=1:overlapCount
                        val = nnz(ismember(cRows,overlap_pts(oindex,:),'rows'));
                        if (val > maxoCount)
                            maxoCount = val;
                            maxo = oindex;
                        end
                    end
                    D = sum((overlap_pts(:,1:3)-overlap_pts(maxo,1:3)).^2,2);
                    cluster_pt = reshape(overlap_pts(maxo,:),1,1,features);
                    for oindex=1:overlapCount
                        if (D(oindex) < bandwidth(1)^2) && ~(oindex == maxo)
                            updateRows = ismember(cRows,overlap_pts(oindex,:),'rows');
                            cRows = cRows.*~updateRows + reshape(cluster_pt,1,[]).*updateRows;
                        end
                    end
                    clusters = reshape(cRows,l,w,[]);
                else
                    cluster_pt = reshape(overlap_pts(1,:),1,1,features);
                end
            else
                cluster_pt = currPt;
            end
            clusters(startY:endY,startX:endX,:) = clusters(startY:endY,startX:endX,:) + (valid-overlap).*cluster_pt;
            cluster_sizes(startY:endY,startX:endX,:) = cluster_sizes(startY:endY,startX:endX,:).*(~valid);
        end
        done = nnz(cluster_sizes) == 0;
%         imshow(lab2rgb(clusters(:,:,1:3)));
%         imshow(clusters(:,:,1),[]);
    end
    clusters(find(clusters == 0)) = NaN;
    clusters = fillmissing(clusters,'nearest');
    clustersXY = clusters(:,:,end-1:end);
    clusters = clusters(:,:,1:end-2);
end

% function [clusters] = computeClusters(currX,bandwidth)
%     l = size(currX,1);
%     w = size(currX,2);
%     features = size(currX,3);
%     clusters = zeros(l*w,features);
%     seeds = zeros(l,w);
%     seeds(floor(bandwidth(2)/2):bandwidth(2):end,floor(bandwidth(2)/2):bandwidth(2):end) = 1;
%     seeds = reshape(seeds,l*w,[]);
%     % loop until all points are tried as seeds
%     xRow = reshape(currX,l*w,[]);
% %     figure;
%     while nnz(seeds)
% %         imshow(lab2rgb(reshape(clusters(:,1:3),l,w,[])));
%         id = find(seeds,1);
%         seeds(id) = 0;
%         idxS = rangesearch(xRow(:,end-1:end),xRow(id,end-1:end),bandwidth(2));
%         idxSR = rangesearch(xRow(idxS{1},1:end-2),xRow(id,1:end-2),bandwidth(1));
%         idxP = idxS{1}(idxSR{1});
%         valids = sum(clusters(idxP,:) == 0,2) == 3;
%         if sum(valids) > bandwidth(3)
%             clusters(id,:) = xRow(id,1:end-2);
%             idx = idxP(valids == 1);
%             seeds(idx) = 0;
%             for i=1:length(idx)
%                 clusters(idx(i),:) = xRow(id,:);
%             end
%         end
% %         % grow a cluster from the next seed
% %         tried = zeros(l,w);
% %         next_pt = find(seeds,1);
% %         tried(next_pt) = 1;
% %         curr_cluster = zeros(l,w);
% %         best_val = [];
% %         best_score = 0;
% %         while next_pt
% %             disp(nnz(curr_cluster.*~tried));
% %             % get next point to try to grow from
% %             [r,c] = ind2sub([l,w],next_pt);
% %             curr_cluster(r,c) = 1;
% %             startY = max(r-bandwidth(2),1);
% %             endY = min(r+bandwidth(2),l);
% %             startX = max(c-bandwidth(2),1);
% %             endX = min(c+bandwidth(2),w);
% %             % find the points that support it in the window that are unassigned
% %             color = sum((currX(startY:endY,startX:endX,1:end-2) - currX(r,c,1:end-2)).^2,3) <= bandwidth(1);
% %             valid = color.*(sum(clusters(startY:endY,startX:endX,:),3)==0);
% %             score = nnz(valid);
% %             if score > best_score
% %                 best_score = score;
% %                 best_val = currX(r,c,1:end-2);
% %             end
% %             % see which ones aren't in the current cluster and add to the
% %             % queue and current cluster
% %             newMask = (curr_cluster(startY:endY,startX:endX)==0).*valid;
% %             curr_cluster(startY:endY,startX:endX) = curr_cluster(startY:endY,startX:endX) + newMask;
% %             next_pt = find(curr_cluster.*~tried,1);
% %             tried(next_pt) = 1;
% %         end
% %         % if a large valid cluster assign all values to the "best value" as
% %         % computer above (aka the one with the most valid in its window
% %         % and remove all of those points from being seeds.
% %         if nnz(curr_cluster) > bandwidth(3)
% %             clusters = clusters.*(~curr_cluster) + curr_cluster.*best_val;
% %             seeds = seeds.*(~curr_cluster);
% %         end
%     end
%     clusters = reshape(clusters,l,w,[]);
% end