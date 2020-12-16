function [result] = normalized_moment(shape,i, j)

centralMoment = central_moment(shape, i, j);
mu00 = central_moment(shape, 0, 0); 
result = centralMoment/(mu00^(1 + ((i+j)/2)));

end

