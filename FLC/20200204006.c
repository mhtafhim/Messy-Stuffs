#include <stdio.h>
int main(void)
{
    FILE *p1, *p2;
    char c;
    p1 = fopen("20200204006.c", "r");
    p2 = fopen("parentheses.txt", "w");
    if (!p1)
        printf("\nFile can't be opened!");
    else
    {
        bool ok = true;
        while ((c = fgetc(p1)) != EOF)
        {
            if(c=='/')
            
            if (c!='\n' && c!=' ' )
                fputc(c, p2);
        }
    }

    
    fclose(p1);
    fclose(p2);
    p2 = fopen("parentheses.txt", "r");
    while ((c = fgetc(p2)) != EOF)
        printf("%c", c);

    fclose(p2);
    return 0;
}