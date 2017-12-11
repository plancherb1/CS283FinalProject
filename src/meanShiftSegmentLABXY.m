function [pts_out] = meanShiftSegmentLABXY(pts,bandwidth,options)
coder.extrinsic('sprintfc');
% Compute the mean shift procedure on the input data and return the segmented data labels
%
% Adapted from:
% Comaniciu and Meer. "Mean Shift: A Robust Approach Toward Feature Space
% Analysis" IEE Transactions on Pattern Analysis and Machine Intelligence.
% Vol. 24, No. 5, May 2002.
    
    % start by flattening to list of vectors
    l = size(pts,1);
    w = size(pts,2);
    feature_size = size(pts,3);
    X = reshape(pts,l*w,feature_size)';
    currX = X;
    
    % then compute spatial list
    [Xs,Ys] = meshgrid(1:l,1:w);
    S = reshape(cat(3,Xs,Ys),l*w,2)';
    currS = S;
    
    % loop until done shifting
    activeIndicies = true(1,l*w);
    mG = (1/(2*pi))^(1/2);
    for i=1:options.maxLoops
        
        % use mean shift on the points
        % loop for now because vectored is too big
        newX = currX;
        newS = currS;
        for index=1:l*w
            if activeIndicies(index)
                D1 = sum((X(:,:)-currX(:,index)).^2,1)./bandwidth(1);
                D2 = sum((S(:,:)-currS(:,index)).^2,1)./bandwidth(2);
                % then compute the kernel of D (including /bandwidth)
                K1 = mG.*exp(-1/2.*(D1));
                K2 = mG.*exp(-1/2.*(D2));
                K = K1.*K2;

                % then compute the vectorized mean shift
                newX(:,index) = sum(X*K',2)/sum(K);
                newS(:,index) = sum(S*K',2)/sum(K);
            end
        end
        
        % see how many indicies are still active and update
        delta = sum((currX-newX).^2,1) + sum((currS-newS).^2,1);
        activeIndicies = delta > options.tolExit;
        countActive = nnz(activeIndicies);
        
        % if debug display stats on iter
        if options.debug
            disp(['[',sprintfc('%d', i),'] countActive: ',sprintfc('%d', countActive)]);
        end
        
        % update variables
        currX = newX;
        currS = newS;
        
        % exit if done
        if(countActive == 0)
            break;
        end
    end
    pts_out = reshape(currX(1:3,:)',l,w,[]);
end