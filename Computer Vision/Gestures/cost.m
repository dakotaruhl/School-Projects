function [result] = cost(M, Q, i, j)
%function takes two points and calcualtes the euclidian distance
%   M and Q are two matricies
%   i, j are indexes


result = sqrt((M(1, i) - Q(1, j))^2 + (M(2, i) - Q(2, j))^2);
end

