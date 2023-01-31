#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long int lli;
const lli mod=1000000007;
const int inf = 999999999;



void printOptimalParens(int i, int j, vector<vector<int>> matrix)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOptimalParens(i, matrix[i][j],matrix);
    printOptimalParens(matrix[i][j]+1, j,matrix);
    cout << ")";
}



int main()
{

    fast
    int n=4;
  //  int p[]= {10,5,1,10,2,10};
  int p[] = {3,2,4,2,5};

    vector< vector<int>> m(n+1, vector<int> (n+1));
    vector< vector<int>> s(n+1, vector<int> (n+1));

    for(int i=1;i<=n;i++)
    {
            m[i][i] = 0;
    }


    int j,q;
    int mx = inf;
    for(int d=2;d<=n;d++)
    {
        for(int i=1 ; i <=n-d+1 ;i++)
        {
            j = i+d-1;
            m[i][j] = inf;
           mx = inf;
            for(int k = i ; k<=j-1 ;k++)
            {
          //      cout << m[i][k] <<"("<< i <<","<<k<< ") + " << m[k+1][j] <<"("<< k+1 <<","<<j<< ") + " << p[i-1] <<"("<< i-1 << ") * " << p[k] << "("<< k<<") * " << p[j] << "("<< j<< ")   |||  ";
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
            //    cout << q << endl ;
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                 //   mx = q;
                }
            }
        }
    }

/*
    cout << endl;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
            cout << setw(8) <<m[i][j] << "  ";
        cout << endl;
    }


    cout << endl;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
            cout << setw(8) <<s[i][j] << "  ";
        cout << endl;
    }

    */

    cout << endl<< endl;

    printOptimalParens(1,4,s);
    cout << " : Minimum cost = " << m[1][5]<< endl;




   return 0;
}

