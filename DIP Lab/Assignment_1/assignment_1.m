
inputImage = imread('20200204006.png'); 

[rows, cols, channels] = size(inputImage);

verticalBarWidth = floor(cols / 6); 
barMask = false(rows, cols);
outputImage = inputImage;

for i = 1:3
    xStart = (2 * i - 1) * verticalBarWidth; 
    xEnd = xStart + verticalBarWidth - 1;  
    outputImage(: , xStart:xEnd , 1) = 0;
    outputImage(: , xStart:xEnd , 2) = 0;
    outputImage(: , xStart:xEnd , 3) = 0;

end


horizontalBarHeight = floor(rows / 5); 
yStart = round(rows / 2) - horizontalBarHeight / 2;
yEnd = yStart + horizontalBarHeight - 1;

outputImage(yStart:yEnd, :, 1) = 255;
outputImage(yStart:yEnd, :, 2) = 0;  
outputImage(yStart:yEnd, :, 3) = 0;  


figure;
imshow(outputImage);
title('Output Image');

% Save the Output Image
imwrite(outputImage, 'outputImage.png');
