#include<stdio.h>
#include <stdbool.h>
int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("input1.c","r");
    fp2 = fopen("output.txt","w");
    char c;
    while((c=fgetc(fp1))!=EOF)
    {
        printf("%c",c);
    }
    rewind(fp1);

    bool quote = false;
    while((c=fgetc(fp1))!=EOF)
    {
        if(c=='"')
        {
            fputc(c,fp2);
            quote = !quote;
        }
        else if(c=='/' && !quote)
        {
            c=fgetc(fp1);
            if(c=='/') ///Single Line Comment Check
            {
                while((c=fgetc(fp1))!='\n');
            }
            else if(c=='*')  ///Multi Line Comment Check
            {
                while(1)
                {
                    while((c=fgetc(fp1))!='*');
                    c=fgetc(fp1);
                    if(c=='/')
                        break;
                    if(c=='*')
                    {
                        fseek (fp1, -sizeof c, SEEK_CUR);
                    }
                }
            }
            else  //If not single or multi line comment, print the / and go back 1 character, so that the last character goes through necessary checks
            {
                fputc('/',fp2);
                fseek (fp1, -sizeof c, SEEK_CUR);
            }

        }
        else if(c==' '  && !quote)
        {
            fputc(c,fp2);
            while((c=fgetc(fp1))==' ');
            fseek (fp1, -sizeof c, SEEK_CUR);
        }
        else if(c!='\n' && c!='\t')
            fputc(c,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fp2 = fopen("output.txt","r");
    while((c=fgetc(fp2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp2);
}

