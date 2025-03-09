img = imread('cameraman.png'); 
if size(img,3) == 3
    img = rgb2gray(img); 
end
img = double(img);

sigma = 5;
k_size = 11;
h_size = floor(k_size / 2);


x_vals = -h_size:h_size;
y_vals = -h_size:h_size;
[X, Y] = meshgrid(x_vals, y_vals);


G = exp(-(X.^2 + Y.^2) / (2 * sigma^2));
G = G / sum(G(:));

[m, n] = size(img);
f_img = zeros(m, n);
pad_img = padarray(img, [h_size, h_size], 'replicate');

for i = 1:m
    for j = 1:n
        region = pad_img(i:i+k_size-1, j:j+k_size-1);
        f_img(i, j) = sum(sum(region .* G));
    end
end

figure;
subplot(1,2,1); imshow(uint8(img)); title('Original Image');
subplot(1,2,2); imshow(uint8(f_img)); title('Filtered Image');
imwrite(uint8(f_img), 'A1_20200204006.jpg');
