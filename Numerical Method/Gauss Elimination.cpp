#include <bits/stdc++.h>

using namespace std;

int main()
{
    int order;
    cin >> order;
    int n = order+1;

    double equ[n][n];


    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> equ[i][j];
        }

    }

    cout << endl;


    //----Forward Elimination----------
    double temp;
    cout << endl;

    for(int k = 0; k<n-2; k++)
    {
        for (int i=k+1; i<n-1; i++)
        {
            temp = (equ[i][k]/equ[k][k]);
            for (int j=k; j<n; j++)
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

    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout  << equ[i][j] << "  ";
        }
        cout << endl;

    }
    cout << endl;


    //-----Backward Substitution---------

    double ans[n];
    double sum = 0;

    ans[n-2] = equ[n-2][n-1]/equ[n-2][n-2];

    for (int k=n-3; k>=0; k--)
    {
        sum = 0;
        for (int j=k+1; j<n-1; j++)
        {
            sum = sum + equ[k][j] * ans[j] ;


        }
        //   cout << "sum : "<< equ[k][n-1] << endl;

        ans[k] = (equ[k][n-1] - sum)/equ[k][k];

    }






    for(int i=0; i<n-1 ; i++)
    {
        cout << "Root : " << ans[i] << endl;
    }







    return 0;
}
