I = imread('peppers_color.jpg'); 
I = rgb2gray(I);
I = double(I); 
A = min(I(:));
B = max(I(:));
D = B - A; 
M = 255; 
R = ((I - A) ./ D) * M + A; 
R = max(0, min(R, M)); 

display(I(1,1));
display(R(1,1));

figure;
subplot(1, 2, 1);
imshow(uint8(I)); 
title('Input Image');
subplot(1, 2, 2);
imshow(uint8(R)); 
title('Output Image');

input_histogram = zeros(1, M + 1);
output_histogram = zeros(1, M + 1);

for i = 1:numel(I)
    input_histogram(I(i) + 1) = input_histogram(I(i) + 1) + 1;
    output_histogram(floor(R(i)) + 1) = output_histogram(floor(R(i)) + 1) + 1;
end

figure;
subplot(1, 2, 1);
bar(0:M, input_histogram, 'k');
title('Histogram of Input Image');
xlabel('Intensity');
ylabel('Frequency');


subplot(1, 2, 2);
bar(0:M, output_histogram, 'r');
title('Histogram of Output Image');
xlabel('Intensity');
ylabel('Frequency');


imwrite(uint8(R), 'T1_output_20200204006.png');