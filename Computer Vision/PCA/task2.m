restoredefaultpath;
clear all;
close all;

addpath E:\Git\Lectures\Code\10_pca\training_data
addpath E:\Git\Lectures\Code\00_common\00_detection
addpath E:\Git\Lectures\Code\00_common\00_images
addpath E:\Git\Lectures\Code\00_common\00_utilities
addpath E:\Git\Lectures\Code\10_pca
addpath E:\Git\Lectures\Data\09_templates\frgc2_b
cd E:\Git\Lectures\Data\09_templates

load_mnist;

%% array of all the number 3 locations in mnist_labels
j = 1; 
labelloc3 = [];
for i = 1:length(mnist_labels)
    if mnist_labels(i) == 3
        labelloc3 = [labelloc3, i]; 
        j = j + 1;
    end
end

%average face method for 3's
image_vertical = 28;
image_horizontal = 28;
total = zeros(image_vertical, image_horizontal);
number = length(labelloc3);

for index = 1: length(labelloc3)
    image = mnist_digits(:,:,index);
    total = total + image;
end
result3 = total / number;

%compute eigenvectors for images with digit 2 
[average3, eigenvectors3, eigenvalues3] = compute_pca(result3(:));

p1 = eigenvectors3(:, 1);
p2 = eigenvectors3(:, 2);
p3 = eigenvectors3(:, 3);
p4 = eigenvectors3(:, 4);
p5 = eigenvectors3(:, 5);

figure(1);
plot([0, p1(1)], [0, p1(2)], 'r-', 'linewidth', 3);
figure(2);
plot([0, p2(1)], [0, p2(2)], 'r-', 'linewidth', 3);
figure(3);
plot([0, p3(1)], [0, p3(2)], 'r-', 'linewidth', 3);
figure(4);
plot([0, p4(1)], [0, p4(2)], 'r-', 'linewidth', 3);
figure(5);
plot([0, p5(1)], [0, p5(2)], 'r-', 'linewidth', 3);