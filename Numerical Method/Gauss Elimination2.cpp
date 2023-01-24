#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;


    double equ[n+2][n+2];


    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            cin >> equ[i][j];
        }

    }

    cout << endl;


    //----Forward Elimination----------
    double temp;
    cout << endl;

    for(int k = 1; k<=n-1; k++)
    {
        for (int i=k+1; i<=n; i++)
        {
            temp = (equ[i][k]/equ[k][k]);
            for (int j=k; j<=n+1; j++)
            {
                //    cout << temp << " ";
                //   cout <<    "(" << equ[i][k]<<"/"<<equ[k][k]<<")" << " " ;
                equ[i][j] = equ[i][j] - temp*equ[k][j];
                //  equ[i][j] = equ[i][j] - (equ[i][k]/equ[k][k])*equ[k][j];
                //    cout <<    "(" << equ[i][k]<<"/"<<equ[k][k]<<")" << " " ;

            }
            //    cout << endl;
        }
        //   cout << endl << endl;
    }

    cout << endl;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cout  << equ[i][j] << "  ";
        }
        cout << endl;

    }
    cout << endl;


    //-----Backward Substitution---------

    double ans[n];
    double sum = 0;

    ans[n] = equ[n][n+1]/equ[n][n];

    for (int k=n-1; k>=1; k--)
    {
        sum = 0;
        for (int j=k+1; j<=n; j++)
        {
            sum = sum + equ[k][j] * ans[j] ;


        }
        //   cout << "sum : "<< equ[k][n-1] << endl;

        ans[k] = (equ[k][n+1] - sum)/equ[k][k];

    }






    for(int i=1; i<=n ; i++)
    {
        cout << "Root : " << ans[i] << endl;
    }







    return 0;
}

