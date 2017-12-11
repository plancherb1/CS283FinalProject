curr_cluster = 1;
clusters = zeros(1,l*w);
guess = 1;
while size(guess,2)
    try
        test = sum((currX(1:3,:) - currX(1:3,guess)).^2,1) < 100;
    catch
        disp(':(');
    end
    clusters(find(test)) = curr_cluster;
    curr_cluster = curr_cluster + 1;
    guess = find(clusters == 0,1);
end
imshow(reshape(clusters,l,w),[])
disp('done');