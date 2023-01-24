#include <bits/stdc++.h>

using namespace std;



int gauss_elimination(int n,double equ[5][5])
{
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
                equ[i][j] = equ[i][j] - temp*equ[k][j];

            }
        }
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

        ans[k] = (equ[k][n+1] - sum)/equ[k][k];

    }


    //----Printing all variables value ----
    for(int i=1; i<=n ; i++)
    {
        cout << "Root : " << ans[i] << endl;
    }



}

void gauss_jordan(int n,double equ[5][5])
{


//------Gauss Jordan-----------

    double pivot;

    for (int i=1; i<=n; i++)
    {
        if(equ[i][i]==0)
        {
            cout << "math error";
            return;
        }
        for (int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                pivot = equ[j][i]/equ[i][i];
                for(int k = 1; k<=n+1; k++)
                {
                    equ[j][k] = equ[j][k] - pivot * equ[i][k];
                }
            }
        }

    }



    cout << endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            cout << equ[i][j] << " ";
        }
        cout << endl;
    }


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



}

void jaccobi(int n,double equ[5][5])
{
    double x[n+1]= {0},temp[n+1];
    double temperror,error,sum,allowed_error=0.000001;


    do
    {
        temperror = 0;
        for(int i = 1; i <= n; i++)
        {
            sum = 0;
            for(int j = 1; j <= n; j++)
            {
                if(j != i)
                {
                    sum = sum + equ[i][j] * x[j];
                }
            }
            temp[i] = (equ[i][n + 1] - sum) / equ[i][i];
            error = fabs(x[i] - temp[i]);
            if(error > temperror)
            {
                temperror = error;
            }
            //x[i] = temp;

        }

        for(int i=1; i<=n; i++)
        {
            x[i] = temp[i];
        }


    }
    while(temperror >= allowed_error);






    for(int i =1; i<=n; i++)
    {
        cout << x[i]<< endl;
    }


}

void gauss_seidel(int n,double equ[5][5])
{
    double x[n+1]= {0},temp;
    double temperror,error,sum,allowed_error=0.000001;


    do
    {
        temperror = 0;
        for(int i = 1; i <= n; i++) //accessing row //limit = number of equations
        {
            sum = 0;
            for(int j = 1; j <= n; j++)//sccessing column
            {
                if(j != i)//avoid diagonal elements
                {
                    sum = sum + equ[i][j] * x[j];
                }
            }
            temp = (equ[i][n + 1] - sum) / equ[i][i];
            error = fabs(x[i] - temp);
            if(error > temperror)
            {
                temperror = error;
            }
            x[i] = temp;

        }

    }
    while(temperror >= allowed_error);






    for(int i =1; i<=n; i++)
    {
        cout << x[i]<< endl;
    }


}



int main()
{

    int n=3;
    //  cin >> n;


    double equ[5][5];


    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            cin >> equ[i][j];
        }

    }

    gauss_elimination(n,equ);

    gauss_jordan(n,equ);

    jaccobi(n,equ);

    gauss_seidel(n,equ);





    return 0;
}


/*


4 1 3 17
1 5 1 14
2 -1 8 12


*/
