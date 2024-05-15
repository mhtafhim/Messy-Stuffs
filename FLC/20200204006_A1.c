#include <stdio.h>

FILE *p1, *p2;



int main()
{
    char c, m;
    p1 = fopen("input2.txt", "r");
    p2 = fopen("newfile.txt", "w");

    while ((c = fgetc(p1)) != EOF)
    {
        char d;

        if (c == '/')
        {
            if ((d = fgetc(p1)) == '*')
            {
                char d, e;

                while ((d = fgetc(p1)) != EOF)
                {
                    if (d == '*')
                    {
                        e = fgetc(p1);

                        if (e == '/')
                            break;
                    }
                }
            }
            else if (d == '/')
            {
                char d, e;

                while ((d = fgetc(p1)) != EOF)
                {
                    if (d == '\n')
                        break;
                }
            }
            else
            {
                fputc(c, p2);
                fputc(d, p2);
            }
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
        }
        else
        {
            fputc(c, p2);
        }
    }

    fclose(p1);
    fclose(p2);

    p2 = fopen("newfile.txt", "r");
    while ((c = fgetc(p2)) != EOF)
        printf("%c", c);

    fclose(p2);
}
