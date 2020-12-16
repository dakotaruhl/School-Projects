function [scores, result_image] = chamfer_search(edge_image, template, scale, number_of_results)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

image = read_gray(edge_image); %%read image as binary
e1 = canny(image, 7);          %%convert to edge image
t1 = template;                 %%template should already be binary

resized = imresize(t1, scale, 'bilinear');  %%resize template to scale
resized = resized > 0;                      %%convert to binary

d1 = bwdist(e1);                            % compute distance transform of edge image.
[r, c] = size(t1);                          

i = 10; j = 30;                             % extract window where hand is located.
window = d1(i:(i+r-1), j:(j+c-1));

sum(sum(resized .* window))                      % compute chamfer distance from t1 to the window

result = imfilter(d1, double(resized), 'symmetric'); % compute image of chamfer distance scores (from template
                                                     % to image windows)
                                                     
scores = imfilter(e1, double(resized), 'symmetric');  %chamfer distance scores                                                     

result = result / max(max(result));         % normalize result, to make scores between 0 and 1.

%result_image = number_of_results white bounding boxes over the best
%matches found during the search
number_of_results = 1;
% superimpose results on top of original image.
result_image = ((result < 0.04) * 255);

end

