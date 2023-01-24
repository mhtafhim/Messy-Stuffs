#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    double equ[n+2][n+2];
    double x[n+1]= {0},temp;
    double temperror,error,sum,allowed_error=0.000001;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            cin >> equ[i][j];
        }

    }



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

    }while(temperror >= allowed_error);






    for(int i =1;i<=n;i++)
    {
        cout << x[i]<< endl;
    }





    return 0;
}
