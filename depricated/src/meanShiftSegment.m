function [pts_out,clusters] = meanShiftSegment(pts,bandwidth,options)
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
    
    % figure out if in LAB or LABXY
    if max(size(bandwidth)) > 1
        ms = @meanShiftLABXY;
    else
        ms = @meanShiftLAB;
    end
    
    % loop until done shifting
    activeIndicies = 1:max(size(X));
    for i=1:options.maxLoops
        
        % use mean shift on the points
        tic
        [newX] = ms(X,currX,bandwidth,activeIndicies);
        t = toc;
        
        % see how many indicies are still active and update
        delta = sum((currX-newX).^2,1);
        activeIndicies = find(delta > options.tolExit);
        countActive = size(activeIndicies,2);
        
        % if debug display stats on iter
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
    imshow(clusters,[])
end