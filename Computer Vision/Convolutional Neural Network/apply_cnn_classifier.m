function [result] = apply_cnn_classifier(image, model, face_size)

image = imresize(image, [31 25]);
face_vertical = face_size(1);
face_horizontal = face_size(2);

vertical_size = size(image, 1);
horizontal_size = size(image, 2);
result = zeros(vertical_size, horizontal_size);
    
    for vertical = 1:(vertical_size-face_vertical+1)
        for horizontal = 1:(horizontal_size-face_horizontal+1)
            response = predict(model, image);
            response1 = response(1, 1);
            row = vertical + round(face_vertical/2);
            col = horizontal + round(face_horizontal/2);
            result(row, col) = result(row, col) + + response1;
        end
    end
end

