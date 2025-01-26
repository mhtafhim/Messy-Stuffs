I = imread('cameraman.png'); % Load grayscale image
[row, col] = size(I);

b = input('Enter the filter size (odd number): ');

if mod(b,2) == 0
    error('Filter size must be an odd number.');
end

filter = ones(b, b) / (b * b); % Normalized averaging filter
x = floor(b / 2); % Padding size

% Manually pad the image with zeros
padded_img = zeros(row + 2*x, col + 2*x, 'uint8');
for i = 1:row
    for j = 1:col
        padded_img(i + x, j + x) = I(i, j);
    end
end

% Extend padding with border replication
for i = 1:x
    padded_img(i, :) = padded_img(x+1, :);
    padded_img(end-i+1, :) = padded_img(end-x, :);
    padded_img(:, i) = padded_img(:, x+1);
    padded_img(:, end-i+1) = padded_img(:, end-x);
end

blurred_img = zeros(row, col, 'uint8');


for i = 1:row
    for j = 1:col
        sum_val = 0;
        for k = 1:b
            for l = 1:b
                sum_val = sum_val + double(padded_img(i+k-1, j+l-1)) * filter(k, l);
            end
        end
        blurred_img(i, j) = uint8(sum_val);
    end
end

% Display the images
figure;
subplot(1, 3, 1); imshow(I); title('Original Image');
subplot(1, 3, 2); imshow(padded_img); title('Padded Image');
subplot(1, 3, 3); imshow(blurred_img); title('Blurred Image');
