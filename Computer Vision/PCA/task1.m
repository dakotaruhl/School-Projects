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
%% Compute average number 2, and eigenvectors/values

%array of all the number 2 locations in mnist_labels
j = 1; 
labelloc2 = [];
for i = 1:length(mnist_labels)
    if mnist_labels(i) == 2
        labelloc2 = [labelloc2, i]; 
        j = j + 1;
    end
end

%average face method for two's
image_vertical = 28;
image_horizontal = 28;
total = zeros(image_vertical, image_horizontal);
number = length(labelloc2);

for index = 1: length(labelloc2)
    image = mnist_digits(:,:,index);
    total = total + image; 
end
result2 = total / number;

%compute eigenvectors for images with digit 2 
[average2, eigenvectors2, eigenvalues2] = compute_pca(result2(:));

p1 = eigenvectors2(:, 1);
p2 = eigenvectors2(:, 2);
p3 = eigenvectors2(:, 3);
p4 = eigenvectors2(:, 4);
p5 = eigenvectors2(:, 5);

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