function result = write_double_matrix2(matrix, fp)

% same as write_double_matrix, but here we pass in a file pointer

result = 0;

rows = size(matrix, 1);
cols = size(matrix, 2);
count = fwrite(fp, [5, rows, cols, 1], 'int32');

if count ~= 4
    disp('failed to write header');
    return;
end

count = fwrite(fp, matrix', 'float64');
result = result';

if count ~= rows * cols
    disp(sprintf('failed to write data, count = %li', count));
    return;
end

result = 1;
