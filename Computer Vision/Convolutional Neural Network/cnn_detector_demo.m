function [result, boxes] = cnn_detector_demo(image, scales, model, face_size, result_number)

boxes = cnn_detector(image, scales, model, face_size, result_number);
result = image;

for number = 1:result_number
    result = draw_rectangle1(result, boxes(number, 1), boxes(number, 2), ...
                             boxes(number, 3), boxes(number, 4));
end

