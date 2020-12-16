function [max_responses, max_scales] = cnn_multiscale_search(image, scales, model, face_size)

max_responses = ones(size(image)) * -10;
max_scales = zeros(size(image));

for scale = scales
    scaled_image = imresize(image, 1/scale, 'bilinear');
    temp_result = apply_cnn_classifier(scaled_image, model, face_size);
    temp_result = imresize(temp_result, size(image), 'bilinear');
    
    higher_maxes = (temp_result > max_responses);
    max_scales(higher_maxes) = scale;
    max_responses(higher_maxes) = temp_result(higher_maxes);
end

