#include<bits/stdc++.h>

using namespace std;



long long int min(long long int a, long long int b)
{
    return (a < b) ? a : b;
}

long long int binomialCoeff(int n, int k)
{
    long long int C[n + 1][k + 1];
    long long int i, j;


    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {

            if (j == 0 || j == i)
                C[i][j] = 1;


            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}


int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        for(int i = 0 ; i<=n ; i++)
        {
            if(i==n)
            {
                cout << binomialCoeff(n,i) ;
                break;
            }

            cout << binomialCoeff(n,i) << " " ;
        }
        cout << endl;
    }
    return 0;
}

