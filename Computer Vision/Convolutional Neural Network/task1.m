restoredefaultpath;
clear all;
close all;

addpath E:\Git\Lectures\Code\15_cnns
addpath E:\Git\Lectures\Data\15_cnns
addpath E:\Git\Lectures\Code\00_common\00_images
addpath E:\Git\Lectures\Code\00_common\00_detection
addpath E:\Git\Lectures\Code\00_common\00_utilities
addpath E:\Git\Lectures\Code\11_boosting
cd E:\Git\Lectures\Data\15_cnns


load faces1000.mat; 
load nonfaces1000.mat;
%% Split the dataset into training and test sets 
facelabels = ones(1000, 1);


for i = 1:1000
    if mod(i,2) == 1
        faces(:,:,i) = nonfaces(:,:,i);
        facelabels(i, 1) = 0;
    end
end

Xtrain = faces(:, :, 1:700);
Ytrain = facelabels(1:700);

Xtest = faces(:, :, 701:end);
Ytest = categorical(facelabels(701:end)); 

%% Transform the data appropriately for input to the network

h = size(Xtrain, 1);
w = size(Xtrain, 2);
c = 1; % Grayscale images have one channel. RGB color images have three channels

N_train = size(Xtrain, 3); % number of training samples

Xtrain = reshape(Xtrain, [h, w, c, N_train]);
Ytrain = categorical(Ytrain); % Labels need to be converted
                              % to categorical values
                              
N_test = size(Xtest, 3);  % number of test samples

Xtest = reshape(Xtest, [h, w, c, N_test]);
Ytest = categorical(Ytest); % Labels need to be converted
                              % to categorical values
                              
layers = [
    imageInputLayer([h w c]) % Dimensions of a single input image.
    
    convolution2dLayer(3, 8, 'Padding','same') % 1st convolutional layer.
    batchNormalizationLayer                    % Batch normalization.
    reluLayer                                  % ReLU activation. 
    
    maxPooling2dLayer(2, 'Stride', 2)          % Max pooling.
    
    convolution2dLayer(3, 16, 'Padding', 'same')% 2nd convolutional layer.
    batchNormalizationLayer
    reluLayer
    
    maxPooling2dLayer(2, 'Stride', 2)
    
    convolution2dLayer(3, 32, 'Padding', 'same')% 3rd convolutional layer.
    batchNormalizationLayer
    reluLayer
    
    fullyConnectedLayer(2)
    softmaxLayer
    classificationLayer];

%% Define network architecture and parameters 

options = trainingOptions('sgdm', ... % Stochastic gradient descent with momentum.
    'InitialLearnRate', 0.01, ...     % Learning rate.
    'MaxEpochs', 4, ...               % How many epochs to train.
    'Shuffle', 'every-epoch', ...     % Shuffle the training data every epoch.
    'Verbose', true, ...              % Show the progress of the training process.
    'Plots', 'training-progress');    % Plot diagrams of the training process.

%% Train the network using the training set

net = trainNetwork(Xtrain, Ytrain, layers, options);

%% Test the network on the test set and calculate the accuracy.

Ypred = classify(net, Xtest); % Predict labels of test data.

probY = predict(net, Xtest); % this wil return prediction probabilities for
                             % each class instead of a class label.
                             % This can be useful when we want to know how
                             % confident the classifier is about each class.
                             
                             

% Accuracy is the fraction of labels that the network predicts correctly. 
% In this case, about 97% of the predicted labels match the 
% true labels of the test set.
accuracy = sum(Ypred == Ytest)/numel(Ytest);
x = sprintf('Accuracy = %s.', accuracy); 
disp(x); 

%% Test functions

photo = read_gray('vjm.bmp');
tic; [result, boxes] = cnn_detector_demo(photo, 1, net, [31, 25], 3); toc
figure(1); imshow(photo, []);
figure(2); imshow(result, [])
