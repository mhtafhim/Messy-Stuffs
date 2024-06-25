#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

char tmp[];
#define Size 20




int tablei = 0;
struct sTable
{
    char name[20][20];
    char idType[20][20];
    char dataType[20][20];
    char scope[20][20];
    char value[20][20];
} sTable;

void insert(char n[], char iT[], char dT[], char scp[], char v[])
{
    strcpy(sTable.name[tablei],n);
    strcpy(sTable.idType[tablei],iT);
    strcpy(sTable.dataType[tablei],dT);
    strcpy(sTable.scope[tablei],scp);
    strcpy(sTable.value[tablei],v);
    tablei++;
}
void update(char n[], char scp[], char v[])
{
    for(int i=0; i<tablei; i++)
    {
        if(strcmp(sTable.name[i],n)==0 && strcmp(sTable.scope[i],scp)==0)
        {
            strcpy(sTable.value[i],v);
            break;
        }
    }
}
void delete()
{
    for(int i = 0 ; i<tablei ; i++)
    {
        free(sTable.name[i]);
    }
}

int search(char n[],char scp[])
{
    for(int i = 0; i<tablei; i++)
    {
        if(strcmp(sTable.name[i],n)==0)
        {
            if(strcmp(sTable.idType[i],"func")==0)
            {
                return (i+1);
            }
            else if(strcmp(sTable.scope[i],scp)==0)
            {
                return (i+1);
            }
        }
    }
    return -1;
}
void display()
{
    printf("\nSl.No.\tName\tId Type\tData Type\tScope\tValue\n-------------------------------------------------------\n");
    for(int i = 0; i<tablei ; i++)
    {
        printf("%d\t|%s\t|%s\t|%s\t\t|%s\t|%s\n",(i+1),sTable.name[i],sTable.idType[i],sTable.dataType[i],sTable.scope[i],sTable.value[i]);
    }
}



void remove_comment2()
{
     FILE *fp1,*fp2;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    char c;

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






void remove_comment()
{
    int cnt = 1;


    FILE *fp1,*fp2;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("ooutput.txt","w");
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

    /*
    fp2 = fopen("ooutput.txt","r");
    while((c=fgetc(fp2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp2);

    */
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


bool isDataType2(char *str)
{
    char temp[1024];
    strcpy(temp,str);
    memmove(temp, temp+1, strlen(temp)); //Remove first Character that is [
    temp[strlen(temp)-1] = '\0'; //Remove last Character that is ]
    char dataTypes[3][10] =
    {
        "double", "float", "int"
    };
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(temp, dataTypes[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}



void leximSeperate2()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("output.txt","r");
    fp2 = fopen("output2.txt","w");
    char c;
    bool quote = false;
    char prev = ' ';
    while((c=fgetc(fp1))!=EOF)
    {
        if(c=='"')
        {
            fputc(c,fp2);
            quote = !quote;
            prev = c;
        }
        else if(quote)
        {
            fputc(c,fp2);
            prev = c;
        }
        else if(c==' ')
        {
            if(prev != ' ')
            {
                fputc(c,fp2);
                prev = c;
            }
            else
            {
                continue;
            }
        }
        else if(isOper(c) || isSepar(c) || isParen(c) || isBrace(c))
        {
            if(prev != ' ')
                fputc(' ',fp2);
            fputc(c,fp2);
            c=fgetc(fp1);
            if(c==EOF)
                break;
            if(isOper(c) && c!=EOF)
            {
                fputc(c,fp2);
            }
            else
            {
                fseek (fp1, -sizeof c, SEEK_CUR);
            }
            fputc(' ',fp2);
            prev = ' ';
        }
        else
        {
            fputc(c,fp2);
            prev = c;
        }
    }
    fclose(fp1);
    fclose(fp2);

    fp3 = fopen("output2.txt","r");
    char cc;
    printf("\nLexeme sep :\n");
    while((cc=fgetc(fp3))!=EOF)
    {
        printf("%c",cc);
    }
    fclose(fp3);




}


void leximSeperate()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("ooutput.txt","r");
    fp2 = fopen("ooutput2.txt","w");
    char c;
    bool quote = false;
    char prev = ' ';
    while((c=fgetc(fp1))!=EOF)
    {
        if(c=='"')
        {
            fputc(c,fp2);
            quote = !quote;
            prev = c;
        }
        else if(quote)
        {
            fputc(c,fp2);
            prev = c;
        }
        else if(c==' ')
        {
            if(prev != ' ')
            {
                fputc(c,fp2);
                prev = c;
            }
            else
            {
                continue;
            }
        }
        else if(isOper(c) || isSepar(c) || isParen(c) || isBrace(c))
        {
            if(prev != ' ')
                fputc(' ',fp2);
            fputc(c,fp2);
            c=fgetc(fp1);
            if(c==EOF)
                break;
            if(isOper(c) && c!=EOF)
            {
                fputc(c,fp2);
            }
            else
            {
                fseek (fp1, -sizeof c, SEEK_CUR);
            }
            fputc(' ',fp2);
            prev = ' ';
        }
        else
        {
            fputc(c,fp2);
            prev = c;
        }
    }
    fclose(fp1);
    fclose(fp2);
/*
    fp3 = fopen("ooutput2.txt","r");
    char cc;
    printf("\nLexeme sep :\n");
    while((cc=fgetc(fp3))!=EOF)
    {
        printf("%c",cc);
    }
    fclose(fp3);


*/

}


void leximCategorize2()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("output2.txt","r");
    fp2 = fopen("output3.txt","w");
    char str[1024];
    while (fscanf(fp1, "%s", str) != EOF)
    {
        if(str[0] == '#')
            fprintf(fp2, "[pre %s] ", str);
        else if(str[0] == '"')
            fprintf(fp2, "[str %s] ", str);
        else if(isKey(str))
            fprintf(fp2, "[kw %s] ", str);
        else if(isSepar(str[0]))
            fprintf(fp2, "[sep %s] ", str);
        else if(isParen(str[0]))
            fprintf(fp2, "[par %s] ", str);
        else if(isOper(str[0]))
            fprintf(fp2, "[op %s] ", str);
        else if(isIdent(str))
            fprintf(fp2, "[id %s] ", str);
        else if(isNumCons(str))
            fprintf(fp2, "[num %s] ", str);
        else if(isBrace(str[0]))
            fprintf(fp2, "[brc %s] ", str);
        else
            fprintf(fp2, "[unkn %s] ", str);
    }
    fclose(fp1);
    fclose(fp2);

     fp3 = fopen("output3.txt","r");
    char c;
    printf("\nLexeme Catagorize :\n");
    while((c=fgetc(fp3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp3);

}




void leximCategorize()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("ooutput2.txt","r");
    fp2 = fopen("ooutput3.txt","w");
    char str[1024];
    memset(str, 0, sizeof(str));
    char cc,d,prev = ' ';
    while((cc=fgetc(fp1))!=EOF)
    {
        if((cc == 'f' || cc == 'i' || cc == 'd')&& (prev == ' ' || prev == '\n') )
        {
            strncat(str, &cc, 1);
            while((d=fgetc(fp1))!=EOF)
            {
                if(d == ' ' || d == '\n')
                {
                    fputc(d,fp2);
                    break;
                }
                strncat(str, &d, 1);
            }

          //  printf("-----(%s)-----",str);

            if(isDataType(str))
            {
                fprintf(fp2 , "%s id ",str);
            }
            else
            {
                fprintf(fp2,("%s ",str));
            }

            memset(str, 0, sizeof(str));
            prev = d;
        }
        else
        {
            fputc(cc,fp2);
            prev = cc;
        }


    }
    fclose(fp1);
    fclose(fp2);

    fp3 = fopen("ooutput3.txt","r");
    char c;
    printf("\n\nLexeme Catagorize :\n");
    while((c=fgetc(fp3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp3);

}



void onlyIdLexemes()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("output3.txt","r");
    fp2 = fopen("output4.txt","w");

   if(fp1 == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    else
    {
        printf("\nFile opened successfully\n");
    }


    char str[1024];
    bool prevId = false;
    while (fscanf(fp1, "%s", str) != EOF)
    {
        if(prevId)
        {
            fprintf(fp2,"%s ",str);
            prevId = false;
        }
        else if(str[0] == '[' && str[1]=='i' && str[2]=='d')
        {
            fprintf(fp2,"%s ",str);
            prevId = true;
        }
        else if(str[0] == '[')
        {
            fprintf(fp2,"[",str);
        }
        else
        {
            fprintf(fp2,"%s ",str);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fp3 = fopen("output4.txt","r");
    char c;
    printf("Only Id lexemes:\n");
    while((c=fgetc(fp3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp3);
}




void symbolTableGenerate()
{
    FILE *fp1;
    fp1 = fopen("output4.txt","r");
    char str[1024];
    char identName[1024];
    char dataType[1024];
    char scope[1024] = "global";
    while (fscanf(fp1, "%s", str) != EOF)
    {
        if(isDataType2(str))
        {
            memmove(str, str+1, strlen(str)); //Remove first Character that is [
            str[strlen(str)-1] = '\0'; //Remove last Character that is ]
            strcpy(dataType,str);
            fscanf(fp1, "%s", str);
            fscanf(fp1, "%s", str);
            str[strlen(str)-1] = '\0';
            strcpy(identName,str);
            fscanf(fp1, "%s", str);
            if(str[1]=='(')
            {
                insert(identName,"func",dataType,scope," ");
                strcpy(scope,identName);
                fscanf(fp1, "%s", str);
                while(true)
                {
                    if(isDataType2(str))
                    {
                        memmove(str, str+1, strlen(str)); //Remove first Character that is [
                        str[strlen(str)-1] = '\0'; //Remove last Character that is ]
                        strcpy(dataType,str);
                        fscanf(fp1, "%s", str);
                        fscanf(fp1, "%s", str);
                        str[strlen(str)-1] = '\0';
                        strcpy(identName,str);
                        insert(identName,"var",dataType,scope," ");
                    }
                    break;
                }
            }
            else if(str[1]=='=')
            {
                fscanf(fp1, "%s", str);
                if(str[1]!='i')
                {
                    memmove(str, str+1, strlen(str)); //Remove first Character that is [
                    str[strlen(str)-1] = '\0'; //Remove last Character that is ]
                    insert(identName,"var",dataType,scope,str);
                    fscanf(fp1,"%s",str);
                }
            }
            else if(str[1]==';')
            {
                insert(identName,"var",dataType,scope," ");
            }
        }
        else if(str[0] == '[' && str[1]=='i' && str[2]=='d')
        {
            fscanf(fp1, "%s", str);
            str[strlen(str)-1] = '\0';
            strcpy(identName,str);
            fscanf(fp1, "%s", str);
            if(str[1]=='=')
            {
                fscanf(fp1, "%s", str);
                if(!(str[1]=='i' && str[2]=='d'))
                {
                    memmove(str, str+1, strlen(str)); //Remove first Character that is [
                    str[strlen(str)-1] = '\0'; //Remove last Character that is ]
                    update(identName,scope,str);
                }
            }
        }
        else if(str[1]=='}')
        {
            strcpy(scope,"global");
        }
    }
    printf("\n\nSymbol Table:\n");
    display();
    fclose(fp1);
}

void modifiedTokenStream()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("output4.txt","r");
    fp2 = fopen("output5.txt","w");

    char str[1024];
    char identName[1024];
    char dataType[1024];
    char scope[1024] = "global";
    while (fscanf(fp1, "%s", str) != EOF)
    {
        if(str[0] == '[' && str[1]== 'i' && str[2]=='d')
        {
            fscanf(fp1, "%s", str);
            str[strlen(str)-1] = '\0';
            strcpy(identName,str);
            fprintf(fp2,"[id %d] ",search(identName,scope));
            fscanf(fp1, "%s", str);
            if(str[1]=='(')
            {
                if(strcmp(scope,"global")==0)
                    strcpy(scope,identName);
            }
            fprintf(fp2, "%s ", str);
        }
        else if(str[1] == '}')
        {
            strcpy(scope,"global");
            fprintf(fp2, "%s ", str);
        }
        else
        {
            fprintf(fp2, "%s ", str);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fp3 = fopen("output5.txt","r");
    char c;
    printf("\nModified Token Stream:\n");
    while((c=fgetc(fp3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp3);
}







int forCheck(char inp[],int k)
{
    k--;
    while(inp[k]==' ' && inp[k]!='(')
    {
        k--;
    }

    if(inp[k]=='(')
    {
        if(inp[k-3]=='f' && inp[k-2]=='o' && inp[k-1]=='r')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}


int error;


void duplicateErrors(char inp[],int inpi)
{
    char linec[Size],linecB[Size],lineP[Size],lineD[Size],lineD2[Size];
    int i=0, ifflag=0;
    int j=0, countB=0,countP=0,k;
    while(inp[i] != ' ')
    {
        linec[j] = inp[i];
        i++;
        j++;
    }
    linec[j] = '\0';
    for(i = 0; i<inpi; i++)
    {
        if(inp[i] == '\n')
        {
            if(countP>0)
            {
                error=1;
                printf("\nUnbalanced '(' at line %s",lineP);
                countP = 0;
            }
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                linec[j] = inp[i];
                i++;
                j++;
            }
            linec[j] = '\0';
        }
        else if(inp[i] == '{')
        {
            countB++;
            strcpy(linecB,linec);
        }
        else if(inp[i] == '}')
            countB--;
        else if(inp[i] == '(')
        {
            countP++;

            strcpy(lineP,linec);
        }
        else if(inp[i]==';')
        {
            k=i;
            k++;
            while(inp[k]!=';' && inp[k]==' ')
                k++;
            if(inp[k]==';')
                if(!forCheck(inp,i))
                {
                    if(strcmp(lineD2,linec))
                    {
                        error=1;
                        printf("\nDuplicate token at line %s",linec);
                        strcpy(lineD2,linec);
                    }
                }
        }
        else if(inp[i] == ')')
            countP--;
        else if(inp[i] == 'i' && inp[i+1] == 'f' && inp[i+2] == '(')
            ifflag++;
        else if(inp[i] == ' ' && inp[i+1] == 'e' && inp[i+2] == 'l' && inp[i+3] == 's' && inp[i+4] == 'e' && inp[i+5] == ' ')
            ifflag--;

        if(countB<0 && strcmp(lineD,linec))
        {
            error=1;
            printf("\nUnbalanced '}' at line %s",linec);
            strcpy(lineD,linec);
            countB=0;
        }
        else if(countB < 0)
            countB = 0;

        if(countP<0 && strcmp(lineP,linec))
        {
            error=1;
            printf("\nUnbalanced ')' at line %s",linec);
            strcpy(lineP,linec);
            countP=0;
        }
        else if(countP < 0)
            countP = 0;
        if(ifflag<0)
        {
            error=1;
            printf("\nUnmatched 'else' at line %s",linec);
            ifflag=0;
        }
    }
    if(countB)
        error=1;
        printf("\nUnbalanced '{' at line %s",linecB);

}


int main()
{

    remove_comment2();
    leximSeperate2();
    leximCategorize2();
    onlyIdLexemes();
    symbolTableGenerate();
    modifiedTokenStream();

    remove_comment();
    leximSeperate();
    leximCategorize();



    FILE *ptr;
    ptr= fopen("ooutput3.txt","r");
    int inpi=0;
    char inp[1000],c;

    while((c=getc(ptr))!=EOF)
    {
        inp[inpi]=c;
        inpi++;
    }
    fclose(ptr);

    printf("\n------------------------------\nErrors:  ");
    duplicateErrors(inp,inpi);





    return 0;
}



