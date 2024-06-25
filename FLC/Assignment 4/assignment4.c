#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

    char tmp[];

void remove_comment()
{
    int cnt = 1;


    FILE *fp1,*fp2;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    char c;

    bool quote = false;
    itoa(cnt,tmp,10);
    fputs(tmp,fp2);
    fputc(' ',fp2);
    cnt++;
    while((c=fgetc(fp1))!=EOF)
    {
        if(c=='\n')
        {
            fputc(c,fp2);
            itoa(cnt,tmp,10);
            fputs(tmp,fp2);
            fputc(' ',fp2);
            cnt++;
        }
        else if(c=='"')
        {
            fputc(c,fp2);
            if(c=='\n')
            {
                fputc(c,fp2);
                itoa(cnt,tmp,10);
                fputs(tmp,fp2);
                fputc(' ',fp2);
                cnt++;
            }
            quote =! quote;
        }
        else if(c=='/' && !quote)
        {
            c=fgetc(fp1);

            if(c=='\n')
            {
                fputc(c,fp2);
                itoa(cnt,tmp,10);
                fputs(tmp,fp2);
                fputc(' ',fp2);
                cnt++;
            }
            else if(c=='/') ///Single Line Comment Check
            {
                while((c=fgetc(fp1))!='\n');
                if(c=='\n')
                {
                    fputc(c,fp2);
                    itoa(cnt,tmp,10);
                    fputs(tmp,fp2);
                    fputc(' ',fp2);
                    cnt++;
                }
            }
            else if(c=='*')  ///Multi Line Comment Check
            {
                while(1)
                {
                    while((c=fgetc(fp1))!='*');
                    c=fgetc(fp1);
                    if(c=='\n')
                    {
                        fputc(c,fp2);
                        itoa(cnt,tmp,10);
                        fputs(tmp,fp2);
                        fputc(' ',fp2);
                        cnt++;
                    }
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
            if(c=='\n')
            {
                fputc(c,fp2);
                itoa(cnt,tmp,10);
                fputs(tmp,fp2);
                fputc(' ',fp2);
                cnt++;
            }
            fseek (fp1, -sizeof c, SEEK_CUR);
        }
        else if(c!='\t')
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



bool isDataType(char *str)
{

    char dataTypes[3][10] =
    {
        "double", "float", "int"
    };



    for (int i = 0; i < 3; i++)
    {
        if (strcmp(str, dataTypes[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}


int isOper(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '!' || c == '>' || c == '<' || c == '&' || c == '|' || c == '^' || c == '~')
        return 1;
    return 0;
}

int isSepar(char c)
{
    if (c == ',' || c == ';' || c == ':' || c == '\'' || c == '\"')
        return 1;
    return 0;
}

int isParen(char c)
{
    if(c == '(' || c == ')' || c == '[' || c == ']')
        return 1;
    return 0;
}

int isBrace(char c)
{
    if(c == '{' || c == '}')
        return 1;
    return 0;
}

int isKey(char *str)
{
    char keywords[32][10] =
    {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    for (int i = 0; i < 32; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isNumCons(char *str)
{
    char state = 'p';
    for(int i = 0; str[i]!=NULL;i++)
    {
        if(state == 'p' && isdigit(str[i]))
        {
            state = 's';
        }
        else if(state == 'p' && str[i]=='.')
        {
            state = 'r';
        }
        else if(state == 's' && str[i]=='.')
        {
            state = 'r';
        }
        else if(state == 's' && isdigit(str[i]))
        {
            state = 's';
        }
        else if(state == 'r' && isdigit(str[i]))
        {
            state = 's';
        }
        else
        {
            return 0;
        }

    }
    return 1;
}

int isIdent(char *str)
{
    char state = 'p';
    for(int i = 0; str[i]!=NULL;i++)
    {
        if(state == 'p' && (isalpha(str[i]) || str[i]=='_'))
        {
            state = 'q';
        }
        else if(state == 'q' && (isalnum(str[i]) || str[i]=='_'))
        {
            state = 'q';
        }
        else
        {
            return 0;
        }

    }
    return 1;
}


void leximCategorize()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("output.txt","r");
    fp2 = fopen("output2.txt","w");
    char str[1024];
    while (fscanf(fp1, "%s", str) != EOF)
    {
        if(isDataType(str))
            fprintf(fp2, "%s id ", str);
        else
            fprintf(fp2,str);

    }
    fclose(fp1);
    fclose(fp2);

    fp3 = fopen("output2.txt","r");
    char c;
    printf("\nLexeme Catagorize :\n");
    while((c=fgetc(fp3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp3);

}





int main()
{
    remove_comment();

    leximSeperate();

leximCategorize();




    return 0;
}



