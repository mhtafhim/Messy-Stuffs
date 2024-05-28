#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

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
    if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
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
            "unsigned", "void", "volatile", "while"};

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
    for (int i = 0; str[i] != '\n'; i++)
    {
        if (state == 'p' && isdigit(str[i]))
        {
            state = 's';
        }
        else if (state == 'p' && str[i] == '.')
        {
            state = 'r';
        }
        else if (state == 's' && str[i] == '.')
        {
            state = 'r';
        }
        else if (state == 's' && isdigit(str[i]))
        {
            state = 's';
        }
        else if (state == 'r' && isdigit(str[i]))
        {
            state = 's';
        }
        else
        {
            return 0;
        }
    }

    if (state == 's')
        return 1;
    else 
        return 0;
}


int isIdent(char *str)
{
    char state = 'p';
    for (int i = 0; str[i] != '\n'; i++)
    {
        if (state == 'p' && (isalpha(str[i]) || str[i] == '_'))
        {
            state = 'q';
        }
        else if (state == 'q' && (isalnum(str[i]) || str[i] == '_'))
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

void leximSeperate()
{
    FILE *fp1, *fp2;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output2.txt", "w");

    if (fp1 == NULL)
    {
        printf("File not found\n");
        return;
    }

    char c;
    bool quote = false;
    char prev = ' ';
    while ((c = fgetc(fp1)) != EOF)
    {
        if (c == '"')
        {
            fputc(c, fp2);
            quote = !quote;
            prev = c;
        }
        else if (quote)
        {
            fputc(c, fp2);
            prev = c;
        }
        else if (c == ' ')
        {
            if (prev != ' ')
            {
                fputc(c, fp2);
                prev = c;
            }
            else
            {
                continue;
            }
        }
        else if (isOper(c) || isSepar(c) || isParen(c))
        {
            if (prev != ' ')
                fputc(' ', fp2);
            fputc(c, fp2);
            c = fgetc(fp1);
            if (c == EOF)
                break;
            if (isOper(c) && c != EOF)
            {
                fputc(c, fp2);
            }
            else
            {
                fseek(fp1, -1, SEEK_CUR);
            }
            fputc(' ', fp2);
            prev = ' ';
        }
        else
        {
            fputc(c, fp2);
            prev = c;
        }
    }
    fclose(fp1);
    fclose(fp2);
}

void leximCategorize()
{
    FILE *fp1, *fp2;
    fp1 = fopen("output2.txt", "r");
    fp2 = fopen("output3.txt", "w");
    char str[1024];
    while (fscanf(fp1, "%s", str) != EOF)
    {
        if (str[0] == '#')
            fprintf(fp2, "[pre %s] ", str);
        else if (str[0] == '"')
            fprintf(fp2, "[str %s] ", str);
        else if (isKey(str))
            fprintf(fp2, "[kw %s] ", str);
        else if (isSepar(str[0]))
            fprintf(fp2, "[sep %s] ", str);
        else if (isParen(str[0]))
            fprintf(fp2, "[par %s] ", str);
        else if (isOper(str[0]))
            fprintf(fp2, "[op %s] ", str);
        else if (isIdent(str))
            fprintf(fp2, "[id %s] ", str);
        else if (isNumCons(str))
            fprintf(fp2, "[num %s] ", str);
        else
            fprintf(fp2, "[unkn %s] ", str);
    }
    fclose(fp1);
    fclose(fp2);
}

int main()
{
    leximSeperate();
    leximCategorize();
}
