function [result] = cnn_detector(image, scales, model, face_size, result_number)


[max_responses, max_scales] = ...
    cnn_multiscale_search(image, scales, model, face_size);

result = detection_boxes(image, zeros(face_size), max_responses, ...
                         max_scales, result_number);
end

