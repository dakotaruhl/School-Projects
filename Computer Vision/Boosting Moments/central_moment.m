function [result] = central_moment(shape,i, j)

m10 = raw_moment(shape, 1, 0);
m01 = raw_moment(shape, 0, 1);
m00 = raw_moment(shape, 0, 0);

xhat = m10/m00;
yhat = m01/m00;

[r,c] = size(shape);
M = 0;
for x = 1:r
    for y = 1:c
        M = M + (x-xhat)^i * (y-yhat)^j * shape(x, y);
    end
end

result = M;
end

