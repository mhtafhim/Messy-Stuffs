I = imread('cyber.jpg');  


G = rgb2gray(I);  
[row, col] = size(G);


R = imnoise(G, 'salt & pepper', 0.03);  

S = R; 


% id = 006
x = 7;
mid = floor(x/2); 
start = mid + 1;

half_col = floor(col/2);


row_end = row - mid; 
col_end = half_col - mid;


for i = start : row_end
    for j = start : col_end
        N = double(R(i-mid:i+mid, j-mid:j+mid)); 
        t = mean(N(:));  
       % t3 = max(N(:)); 


        S(i, j) = uint8(t); 
       % S(i, j) = uint8(t3);
    end
end


col_end = col - mid;

for i = start : row_end
    for j = half_col : col_end
        N = double(R(i-mid:i+mid, j-mid:j+mid)); 
      %  t = mean(N(:));  
        t3 = max(N(:)); 


     %   S(i, j) = uint8(t); 
        S(i, j) = uint8(t3);
    end
end




figure;
subplot(2, 2, 1);
imshow(I);
title('Original Image');



subplot(2, 2, 2);
imshow(G);
title('Gray Image');

imwrite(uint8(bit2_img), 'T2_output1_20200204006.png');

subplot(2, 2, 3);
imshow(R);
title('Noisy Image');


subplot(2, 2, 4);
imshow(S);
title('Mean Filtered');



