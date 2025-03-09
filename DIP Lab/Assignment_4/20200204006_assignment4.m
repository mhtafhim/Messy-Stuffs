
img = imread('cameraman.png'); % Replace with your image
if size(img,3) == 3
    img = rgb2gray(img); % Convert to grayscale
end
img = double(img);

% User-defined sigma value
sigma = input('Enter the sigma value: ');

% Define kernel size based on roll number (modify accordingly)
roll_number = input('Enter your roll number: ');
kernel_sizes = [7, 9, 11, 13];
kernel_size = kernel_sizes(mod(roll_number, 4) + 1);
half_size = floor(kernel_size / 2);

% Generate X and Y matrices
[X, Y] = meshgrid(-half_size:half_size, -half_size:half_size);

% Compute Gaussian Kernel
gaussian_kernel = exp(-(X.^2 + Y.^2) / (2 * sigma^2));
gaussian_kernel = gaussian_kernel / sum(gaussian_kernel(:));

% Apply filter manually
[m, n] = size(img);
filtered_img = zeros(m, n);
pad_size = half_size;
padded_img = padarray(img, [pad_size, pad_size], 'replicate');

for i = 1:m
    for j = 1:n
        region = padded_img(i:i+kernel_size-1, j:j+kernel_size-1);
        filtered_img(i, j) = sum(sum(region .* gaussian_kernel));
    end
end

% Display results
figure;
subplot(1,2,1); imshow(uint8(img)); title('Original Image');
subplot(1,2,2); imshow(uint8(filtered_img)); title('Filtered Image');
