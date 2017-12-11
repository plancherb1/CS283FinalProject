function [pts_out,clusters] = meanShiftSegment2(pts,kernel_type,bandwidth,options)
% Compute the mean shift procedure on the input data and return the segmented data labels
%
% Adapted from:
% Comaniciu and Meer. "Mean Shift: A Robust Approach Toward Feature Space
% Analysis" IEE Transactions on Pattern Analysis and Machine Intelligence.
% Vol. 24, No. 5, May 2002.
    % parameters
    if nargin < 3
        error("Invlaid usage: pts, kernel_type, bandwidth, [options]");
    elseif nargin == 3
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

    % start by flattening to list of vectors
    l = size(pts,1);
    w = size(pts,2);
    feature_size = size(pts,3);
    X = reshape(pts,l*w,feature_size)';
    currX = X;
    
    % precompute multipliers
    mE = 9/(8*pi);
    mG = (1/(2*pi))^(1/2);
    
    % define Kernel functions
    if kernel_type == "E" % Epanechnikov
        kernel = @(D)(max(mE.*(1-(D)),0));
    elseif kernel_type == "G"% Gausian
        kernel = @(D)(mG.*exp(-1/2.*(D)));
    else
        error("Invalid Kernel Type: options are [E]panechnikov or [G]ausian")
    end
    
    % define distance function
    % super efficient pairwise vectorized distance matrix thanks to 
    % https://statinfer.wordpress.com/2011/11/14/efficient-matlab-i-pairwise-distances/
    distance = @(X,x)(sum((X-x).^2,1)./bandwidth(1));%pdist(X'); %bsxfun(@plus,dot(X,X,1)',dot(X,X,1))-2*(X'*X);
    if max(size(bandwidth)) > 1
        distance = {distance,@(X,x)(sum((X-x).^2,1)./bandwidth(2))};
        ms = @meanShiftLABXY;
    else
        ms = @meanShiftLAB;
    end
    
    % loop until done shifting
    activeIndicies = 1:max(size(X));
    for i=1:options.maxLoops
        
        % use mean shift on the points
        tic
        [newX] = ms(X,currX,kernel,distance,activeIndicies);
        t = toc;
        
        % see how many indicies are still active and update
        delta = sum((currX-newX).^2,1);
        activeIndicies = find(delta > options.tolExit);
        
        % display stats on iter
        countActive = size(activeIndicies,2);
        disp(['[',num2str(i),'] countActive: ',num2str(countActive),' time: ',num2str(t)]);
        % if debug display points
        if options.debug
            imshow(lab2rgb(reshape(currX(1:3,:)',l,w,[])));
        end
        
        % update variables
        currX = newX;
        
        % exit if done
        if(countActive == 0)
            break;
        end
    end
    pts_out = reshape(currX(1:3,:)',l,w,[]);
    
    % now find the clusters in X (means that shifted to within tol)
    curr_cluster = 1;
    clusters = zeros(1,l*w);
    guess = 1;
    while size(guess,2)
        try
            test = sum((currX(1:3,:) - currX(1:3,guess)).^2,1) < options.tolCluster;
        catch
            disp(':(');
        end
        clusters(find(test)) = curr_cluster;
        curr_cluster = curr_cluster + 1;
        guess = find(clusters == 0,1);
    end
    clusters = reshape(clusters,l,w);
%     imshow(clusters,[])
end

function [newX] = meanShiftLABXY(X,currX,kernel,distance,activeIndicies)
    % loop for now because vectored is too big
    distanceXY = distance{2};
    distance = distance{1};
    newX = currX;
    for i=1:size(activeIndicies,2)
        index = activeIndicies(i);
        D1 = distance(X(1:3,:),currX(1:3,index));
        D2 = distanceXY(X(4:5,:),currX(4:5,index));
        % then compute the kernel of D (including /bandwidth)
        K1 = kernel(D1);
        K2 = kernel(D2);
        K = K1.*K2;

        % then compute the vectorized mean shift
        newX(:,index) = sum(X*K',2)/sum(K);
    end
end

function [newX] = meanShiftLAB(X,currX,kernel,distance,activeIndicies)
    % loop for now because vectored is too big
    newX = currX;
    for i=1:size(activeIndicies,2)
        index = activeIndicies(i);
        D = distance(X,currX(:,index));

        % then compute the kernel of D (including /bandwidth)
        K = kernel(D);

        % then compute the vectorized mean shift
        newX(:,index) = sum(X*K',2)/sum(K);
    end
end