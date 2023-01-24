#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    double a[n+2][2*(n+2)];
    double pivot;
    cout << fixed << setprecision(3) ;



    for(int k=1; k<=n; k++)
    {
        for(int j=1; j<=2*n; j++)
        {
          //  printf("Co-efficient of a[%d][%d] = ", k,j);
            cin>>a[k][j];
        }
    }


    for(int i=1; i<=n; i++)
    {
        if(a[i][i]==0.0)
        {
            cout<<"Mathematical Error!"<<endl;
            return 0;
        }
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                pivot = a[j][i]/a[i][i];
                for(int k=1; k<=2*n; k++)
                {

                    a[j][k]=a[j][k]-pivot*a[i][k];

                }
            }
        }
    }



    for(int k=1; k<=n; k++)
    {
        for(int j=1; j<=2*n; j++)
        {
            cout<<a[k][j] << "   ";

        }
        cout << endl<<endl;
    }




    for(int i=1; i<=n; i++)
    {
        for(int j=n+1; j<=2*n; j++)
        {
            a[i][j] = a[i][j]/a[i][i];
            a[i][j-n] = a[i][j-n]/a[i][i];
        }
    }


    for(int k=1; k<=n; k++)
    {
        for(int j=1; j<=2*n; j++)
        {
            cout<<a[k][j] << "   ";

        }
        cout << endl<<endl;
    }








    return 0;
}



/*

   3
4 1 3 1 0 0
1 5 1 0 1 0
2 -1 8 0 0 1

3
4 1 3 17
1 5 1 14
2 -1 8 12


    printf("Enter Constant vector\n");
    for(i=1;i<=n;i++)
    {
        cin>>d[i];
    }
*/
