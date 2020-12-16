function [r_mean,r_std, g_mean, g_std] = rgmeanStd(patch)
%Function that takes a patch of an image as an input and returns the mean
%and Std values for that patch. 
%   Detailed explanation goes here
sample_red = patch(:, :, 1);
sample_green = patch(:, :, 2);
sample_blue = patch(:, :, 3);

%
sample_red = sample_red(:);
sample_green = sample_green(:);
sample_blue = sample_blue(:);

% compute the mean and std for each color - normalized RG space

sample_total = sample_red + sample_green + sample_blue;
sample_red2 = sample_red ./ sample_total;
sample_red2(isnan(sample_red2)) = 0; % when (R+G+B) == 0, a division by 0 can result in a NaN
sample_green2 = sample_green ./ sample_total;
sample_green2(isnan(sample_green2)) = 0;

r_mean = mean(sample_red2);
g_mean = mean(sample_green2);
r_std = std(sample_red2);
g_std = std(sample_green2);
end

