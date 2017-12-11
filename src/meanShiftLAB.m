function [newX] = meanShiftLAB(X,currX,bandwidth,activeIndicies)
    
    % loop for now because vectored is too big
    mG = (1/(2*pi))^(1/2);
    newX = currX;
    for i=1:size(activeIndicies,2)
        index = activeIndicies(i);
        D = sum((X-currX(:,index)).^2,1)./bandwidth(1);

        % then compute the kernel of D (including /bandwidth)
        K = mG.*exp(-1/2.*(D));

        % then compute the vectorized mean shift
        newX(:,index) = sum(X*K',2)/sum(K);
    end
end