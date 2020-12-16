%Change pathnames to your directory
%this script uses a function i made
%rgmeanStd.m 


restoredefaultpath;
clear all;
close all;

addpath E:\Git\Lectures\Code\00_common\00_detection
addpath E:\Git\Lectures\Code\00_common\00_images
addpath E:\Git\Lectures\Code\00_common\00_utilities
addpath E:\Git\Lectures\Code\07_skin
cd E:\Git\Lectures\Data\07_skin
%%
%Module 1

trainingFrame = double(imread('training_A.bmp'));
patch1 = trainingFrame(122:150, 297:338, :);
patch2 = trainingFrame(246:265, 117:145, :);   

%compute the mean and std for each color - normalized RG space

[r_mean1, r_std1, g_mean1, g_std1] = rgmeanStd(patch1);  
[r_mean2, r_std2, g_mean2, g_std2] = rgmeanStd(patch2);  

%average values for Std and Mean between the two patches
r_mean = (r_mean1 + r_mean2)/2;
r_std = (r_std1 + r_std2)/2;
g_mean = (g_mean1 + g_mean2)/2;
g_std = (g_std1 + g_std2)/2;

%Test on an image

frame20 = double(imread('frame20.bmp'));
[rows,cols, bands] = size(frame20);

skin_detection1 = zeros(rows, cols);

for row = 1:rows
    for col = 1:cols
        red = frame20(row, col, 1);
        green = frame20(row, col, 2);
        blue = frame20(row, col, 3);
    
        sum = red+green+blue;
        if sum > 0
            r = red / sum;
            g = green / sum;
        else
            r = 0;
            g = 0;
        end
        
        r_prob = gaussian_probability(r_mean, r_std, r);
        g_prob = gaussian_probability(g_mean, g_std, g);
        prob = r_prob * g_prob;
        skin_detection1(row, col) = prob;
    end
end

figure(1); imshow(skin_detection1, []);
figure(2); imshow(skin_detection1 > 10, []);

%%
%Module 2
trainingFrame = double(imread('training_B.bmp'));
patch1 = trainingFrame(189:230, 213:293, :);
patch2 = trainingFrame(376:423, 63:120, :);  
patch3 = trainingFrame(413:471, 404:455, :); 

%compute the mean and std for each color - normalized RG space

[r_mean1, r_std1, g_mean1, g_std1] = rgmeanStd(patch1);  
[r_mean2, r_std2, g_mean2, g_std2] = rgmeanStd(patch2);  
[r_mean3, r_std3, g_mean3, g_std3] = rgmeanStd(patch3);

%average values for Std and Mean between the two patches
r_mean = (r_mean1 + r_mean2 + r_mean3)/3;
r_std = (r_std1 + r_std2 + r_std3)/3;
g_mean = (g_mean1 + g_mean2 + g_mean3)/3;
g_std = (g_std1 + g_std2 + g_std3)/3;

%Test on an image

frame20 = double(imread('frame20.bmp'));
[rows,cols, bands] = size(frame20);

skin_detection2 = zeros(rows, cols);

for row = 1:rows
    for col = 1:cols
        red = frame20(row, col, 1);
        green = frame20(row, col, 2);
        blue = frame20(row, col, 3);
    
        sum = red+green+blue;
        if sum > 0
            r = red / sum;
            g = green / sum;
        else
            r = 0;
            g = 0;
        end
        
        r_prob = gaussian_probability(r_mean, r_std, r);
        g_prob = gaussian_probability(g_mean, g_std, g);
        prob = r_prob * g_prob;
        skin_detection2(row, col) = prob;
    end
end

figure(3); imshow(skin_detection2, []);
figure(4); imshow(skin_detection2 > 10, []);

%%
%Module 3
%The detect_skin function, called with histograms read from positives.bin and negatives.bin.
%The following is an example of how to call the detect_skin function:

negative_histogram = read_double_image('negatives.bin');

positive_histogram = read_double_image('positives.bin');

frame20 = double(imread('frame20.bmp'));

skin_detection3 = detect_skin(frame20, positive_histogram,  negative_histogram);





testingFrame = double(imread('test.bmp'));

%Compute the skin accuracy and nonskin accuracy for thresholds 1-100
skinArray = 1:100; 
nonskinArray = 1:100; 
thresholds = 100;

for threshold = 1: thresholds
    
        [skin_accuracy, nonskin_accuracy] = eval_module(testingFrame, threshold);
        skinArray(threshold) = skin_accuracy; 
        nonskinArray(threshold) = nonskin_accuracy;
end

%now we have a baseline for accuracy among 100 thresholds, we test against
%our 3 modules probability modules?? I can't figure this part out

