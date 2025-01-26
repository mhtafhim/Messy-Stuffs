I = imread('cameraman.png'); 
I = double(I); 

bit2 = mod(floor(I / 2), 2); 
bit4 = mod(floor(I / 8), 2);  
bit6 = mod(floor(I / 32), 2); 
bit8 = mod(floor(I / 128), 2); 

bit2_img = bit2 * 2; 
bit4_img = bit4 * 16;
bit6_img = bit6 * 64;
bit8_img = bit8 * 128;

figure;
subplot(3, 2, 1);
imshow(uint8(I));
title('Original Image');

subplot(3, 2, 2);
imshow(uint8(bit2_img));
title('2nd Bit Plane');

subplot(3, 2, 3);
imshow(uint8(bit4_img));
title('4th Bit Plane');

subplot(3, 2, 4);
imshow(uint8(bit6_img));
title('6th Bit Plane');

subplot(3, 2, 5);
imshow(uint8(bit8_img));
title('8th Bit Plane');


imwrite(uint8(bit2_img), 'T2_output1_20200204006.png');
imwrite(uint8(bit4_img), 'T2_output2_20200204006.png');
imwrite(uint8(bit6_img), 'T2_output3_20200204006.png');
imwrite(uint8(bit8_img), 'T2_output4_20200204006.png');
