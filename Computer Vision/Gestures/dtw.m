function [result] = dtw(sequence1, sequence2)
%DTW takes as input two sequences and computes the dynamic time warping (DTW) 
%distance between the sequences.

%   In particular, each sequence is a matrix that has two rows. The number 
%   of columns for each sequence can be any integer >= 1. Each column in the 
%   sequence represents a 2D point. For example, suppose that we have a 
%   gesture with 20 frames, and we have a hand detector that has computed 
%   the center of the hand location in each of the 20 frames. The center of 
%   the hand location at each frame is a single pixel value, specified using 
%   two numbers. The sequence representing that video will have 20 columns, 
%   where the i-th column stores the hand location at the i-th frame.

%% initialization

clear;
close;

% sequence1 = [0.30 0.40 0.50 0.60 0.50 0.40 0.30 0.40 0.50 0.60;
%              0.80 0.90 0.90 0.80 0.60 0.50 0.40 0.40 0.40 0.40]; 
% sequence2 = [0.29 0.36 0.46 0.58 0.53 0.46 0.36 0.29 0.43 0.54 0.59 0.6077;
%              0.80 0.89 0.89 0.81 0.66 0.57 0.47 0.40 0.40 0.40 0.42 0.4299];

% sequence1 = [0.10 0.17 0.24 0.31 0.36 0.40 0.42 0.46 0.50 0.57 0.64 0.71 0.74 0.77 0.81  0.83  0.86 0.90 0.95 0.99;
% 0.30 0.38 0.49 0.54 0.54 0.47 0.37 0.29 0.25 0.26 0.26 0.26 0.31 0.38 0.38 0.32 0.25 0.25 0.24 0.25];
% sequence2 = [0.13 0.18 0.21 0.25 0.29 0.32 0.38 0.42 0.42 0.45 0.47 0.51 0.56 0.63 0.67 0.72 0.74 0.77 0.79 0.81 0.83 0.87 0.92 0.97;
% 0.29 0.31 0.32 0.38 0.47 0.52 0.54 0.52 0.46 0.37 0.32 0.28 0.26 0.26 0.26 0.35 0.38 0.38 0.34 0.28 0.25 0.25 0.26 0.24];
 
M = sequence1; Q = sequence2;

scores = zeros(length(M), length(Q));
scores(1,1) = cost(M, Q, 1, 1);

for i=2:length(M)
    scores(i,1) = scores(i-1, 1) + cost(M, Q, i, 1);
end

for j=2:length(Q)
    scores(1, j) = scores(1, j-1) + cost(M, Q, 1, j);
end

%% main loop

for i=2:length(M)
    for j=2:length(Q)
        scores(i,j)= cost(M, Q, i, j) + min(min(scores(i-1, j), scores(i, j-1)), scores(i-1, j-1));
    end
end

result = scores(length(M), length(Q)); 
end

