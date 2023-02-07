#include <bits/stdc++.h>

using namespace std;

int c[1000][1000];
int b[1000][10000];
/*
1 = upper;
2 = left;
3 = diagonal;
*/


void print_LCS(string s1,int i ,int j)
{

    if(i==0 || j==0)
        return;
    if(b[i][j]==3)
    {
        print_LCS(s1,i-1,j-1);
      //  cout << s1[i];
      //  cout << i << " " << j << endl;
        cout << s1[i-1];

    }
    else if(b[i][j]==1)
        print_LCS(s1,i-1,j);
    else
        print_LCS(s1,i,j-1);

}

void lcs(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();

    for(int i = 0 ;i<m;i++)
    {
       c[i][0] =0;
       c[0][i] = 0;
    }

    for(int i =1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j] = c[i-1][j-1] +1;
                b[i][j] = 3;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 2;
            }
        }
    }

    /*
    for(int i =0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    */


     print_LCS(s1,m,n);

}


int main()
{
    string s1,s2;

    s1 = "BDCAB";
    s2 = "ABCB";


    lcs(s2,s1);



   return 0;
}
