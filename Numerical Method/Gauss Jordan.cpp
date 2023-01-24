#include <bits/stdc++.h>

using namespace std;

int main()
{

    int order ;
    cin >> order ;
    int n = order;

    double equ[n+2][n+2];

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            cin >> equ[i][j];
        }

    }


//------Gauss Jordan-----------

    double pivot;

    for (int i=1; i<=n; i++)
    {
        if(equ[i][i]==0)
        {
            cout << "math error";
            return 0;
        }
        for (int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                pivot = equ[j][i]/equ[i][i];
                cout <<  equ[j][i] << " " << equ[i][i] ;
                for(int k = 1; k<=n+1; k++)
                {
                    equ[j][k] = equ[j][k] - pivot * equ[i][k];
                }

                cout << endl << endl ;
                for (int i=1; i<=n; i++)
                {
                    for (int j=1; j<=n+1; j++)
                    {
                        cout << equ[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;

            }
        }

    }



    cout << endl << endl ;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            cout << equ[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    double ans[n+1];
    //--------Obtaining Result--------

    for(int i =1; i<=n; i++)
    {
        ans[i] = equ[i][n+1]/equ[i][i];
    }



    for(int i =1; i<=n; i++)
    {
        cout << ans[i]<< endl;
    }




    return 0;
}

