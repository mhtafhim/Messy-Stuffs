#include <stdio.h>


FILE *p1, *p2;


void ForMultiLine()
{

    char d,e;

    while((d=fgetc(p1))!=EOF)
    {
        if(d=='*')
        {
            e=fgetc(p1);

            if(e=='/')
                return;
        }
    }

}


void forSingleLine()
{
    char d,e;

    while((d=fgetc(p1))!=EOF)
    {
        if(d=='\n')
            return;

    }

}

int main()
{
    char c,m;
    p1 = fopen ("input.txt","r");
    p2 = fopen ("newfile.txt","w");


    while((c=fgetc(p1)) != EOF)
    {
        char d;

        if( c == '/')
        {
            if((d=fgetc(p1))=='*')
                ForMultiLine();

            else if( d == '/')
            {
                forSingleLine();
            }
            else
            {
                fputc(c,p2);
                fputc(d,p2);
            }
        }
        else if(c == ' ' || c == '\n' || c == '\t')
        {

        }
        else
        {
            fputc(c,p2);
        }


    }

    fclose(p1);
    fclose(p2);

    p2 = fopen("parentheses.txt", "r");
    while ((c = fgetc(p2)) != EOF)
        printf("%c", c);

    fclose(p2);
}

