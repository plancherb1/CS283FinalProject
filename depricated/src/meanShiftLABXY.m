function [newX] = meanShiftLABXY(X,currX,bandwidth,activeIndicies)
    
    % loop for now because vectored is too big
    mG = (1/(2*pi))^(1/2);
    
    newX = currX;
    for i=1:size(activeIndicies,2)
        index = activeIndicies(i);
        D1 = sum((X(1:3,:)-currX(1:3,index)).^2,1)./bandwidth(1);
        D2 = sum((X(4:5,:)-currX(4:5,index)).^2,1)./bandwidth(2);
        % then compute the kernel of D (including /bandwidth)
        K1 = mG.*exp(-1/2.*(D1));
        K2 = mG.*exp(-1/2.*(D2));
        K = K1.*K2;

        % then compute the vectorized mean shift
        newX(:,index) = sum(X*K',2)/sum(K);
    end
end