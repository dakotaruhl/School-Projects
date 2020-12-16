% Before you run this code, make sure that you are in the right directory.
%
% First, download the zip files containing code and data for this unit, from 
% the lectures web page (accessible from the course website).
% 
% Second, unzip the zip files.
%
% Third, modify the addpath and cd commands in the beginning of the code,
% to reflect the locations of code and data on your computer
%
% Now you can copy lines from this script file and paste them to Matlab's
% command window.

%%

% The addpath and cd lines are the only lines in the code that you may have
% to change, in order to make the rest of the code work. Adjust
% the paths to reflect the locations where you have stored the code 
% and data in your computer.

restoredefaultpath;
clear all;
close all;

addpath E:\Git\Lectures\Code\00_common\00_detection
addpath E:\Git\Lectures\Code\00_common\00_images
addpath E:\Git\Lectures\Code\00_common\00_utilities
addpath E:\Git\Lectures\Code\08_chamfer
cd E:\Git\Lectures\Data\08_chamfer


%%

% read an image

clear; close all;
image = read_gray('clutter1.bmp');
figure(1); imshow(image, []);
e1 = canny(image, 7);
figure(2); imshow(e1);

%%

% read a template

t1 = read_gray('hand_lf1.bmp');

% resize template to scale that matches the hand size in the image
t1 = imresize(t1, 0.3, 'bilinear');

% convert to binary image
t1 = t1 > 0;

% compute distance transform of edge image.
d1 = bwdist(e1);
[r, c] = size(t1);

% extract window where hand is located.
i = 10; j = 30;
window = d1(i:(i+r-1), j:(j+c-1));

% compute chamfer distance from t1 to the window
sum(sum(t1 .* window))

%%

% compute image of chamfer distance scores (from template
% to image windows) with no scaling

result = imfilter(d1, double(t1), 'symmetric');

% normalize result, to make scores between 0 and 1.
result = result / max(max(result));
figure(1); imshow(e1);
figure(2); imshow(result < .04, []);

% superimpose results on top of original image.
figure(3); imshow(max(image * 0.5, (result < 0.04) * 255), []);

%%

% compute chamfer scores for a specific scale

s = 0.95;
resized = imresize(image, s, 'bilinear');
resized_edges = canny(resized, 7);
resized_dt = bwdist(resized_edges);
chamfer_scores = imfilter(resized_dt, double(t1), 'symmetric');

figure(3); imshow(chamfer_scores, []);
%%
[scores, result_image] = chamfer_search(image, t1, .9, 1);
imshow(result_image); 