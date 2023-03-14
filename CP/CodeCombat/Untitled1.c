#include <stdio.h>

void merge_strings(char dest[], char src[]) {
    int i, j;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++, i++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
}

int main() {
    char str1[50], str2[50];


    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);


    merge_strings(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}
