function [centeredbestmatching] = pca_detect_digit(image,mean_digit, eigenvectors, N)
%%
% store in v1 and f1 an example number image (v1 is a vectorized form 
% of f1).

digit_size = [28, 28];
v1 = image;
f1 = reshape(v1, digit_size);

% execute this chunk of code again and again to see
% how the face is reconstructed using more and more
% eigenvectors. k is the number of eigenvectors used.
N = N+1

% compute the approximation of f1 obtained using the first N eigenvectors.
ev = eigenvectors(:, 1:N);
p = pca_projection(f1, mean_digit, ev);
b = pca_backprojection(p, mean_digit, ev);
rb = reshape(b, digit_size);

rrb = imresize(rb, 9, 'bilinear');

center = size(rrb)/2; 
centeredbestmatching = rrb(center); 
end

