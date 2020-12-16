function [result] = hu_moment(shape,m)


n02 = normalized_moment(shape, 0, 2);
n03 = normalized_moment(shape, 0, 3);

n11 = normalized_moment(shape, 1, 1);
n12 = normalized_moment(shape, 1, 2);

n20 = normalized_moment(shape, 2, 0);
n21 = normalized_moment(shape, 2, 1);

n30 = normalized_moment(shape, 3, 0);


a = (n30 - (3*n12)) * (n30 + n12);
aa = a * (((n30 + n12)^2) - (3*((n21 + n03)^2))); 
b = (3*n21 - n03) * (n21 + n03);
bb = b * (3*(n30 + n12)^2 - (n21 + n03)^2);

if m == 1; result = n20 + n02; end 
if m == 2; result = (n20 - n02)^2 + (2*n11)^2; end
if m == 3; result = (n30 - 3*n12)^2 + (3*n21 - n03)^2; end
if m == 4; result = (n30 + n12)^2 + (n21 + n03)^2; end
if m == 5; result = aa + bb; end
if m == 6; result = ((n20 - n02) * ((n30 + n12)^2 - (n21 + n03)^2)) + (4*n11*(n30 + n12)*(n21+n03)); end
if m == 7; result = (((3*n21 - n03) * (n30 + n12)) * ((n30 + n12)^2 - (3*(n21 + n03)^2))) - ((n30 - (3*n12)) * (n21 + n03) * ((3*(n30 + n12)^2) - (n21 + n03)^2)); end
end

