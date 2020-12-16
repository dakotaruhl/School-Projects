function [result,start_frame, end_frame] = dtw2(sequence1, sequence2)
%Recieves two seqeunces and returns the DTW distance between the two
%sequences, as well as the start and end frame of the gesture identified. 

%% initialization

clear;
close;

%sequence1 = [0.69 0.72 0.72 0.76 0.81 0.82 0.84 0.87;
%0.26 0.26 0.30 0.38 0.38 0.30 0.26 0.25];
%sequence2 = [0.10 0.17 0.24 0.31 0.36 0.40 0.42 0.46 0.50 0.57 0.64 0.71 0.74 0.77 0.81 0.83 0.86 0.90 0.95 0.99;
%0.30 0.38 0.49 0.54 0.54 0.47 0.37 0.29 0.25 0.26 0.26 0.26 0.31 0.38 0.38 0.32 0.25 0.25 0.24 0.25];

M = sequence1;
Q = sequence2;

scores = zeros(length(M), length(Q));
scores(1:length(M),1) = 9999;
scores(1,1) = 0; 
%% main loop

for i=2:length(M)
    for j=2:length(Q)
        scores(i,j)= cost(M, Q, i, j) + min(min(scores(i-1, j), scores(i, j-1)), scores(i-1, j-1));
    end
end


end_frame_value = min(scores(size(scores, 1), 2:length(scores)));
[~, end_frame] = find(scores == end_frame_value);

start_frame_value = min(scores(2,2:end));
[~, start_frame] = find(scores == start_frame_value);
result = scores(length(M), end_frame+1);
end

