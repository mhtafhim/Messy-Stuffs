#include <bits/stdc++.h>

using namespace std;


double func(double arr[],double degree,double x)
{

    double result = arr[0];

    for (int i=1; i<=degree; i++)
        result = result*x + arr[i];


    return result;

}


void allPossibleRoot()
{
    double ds=0.0001,error=0.00000001;
 //   int degree;

    //  cin >> a>>b>>ds>>degree>>error;

    double poly[] = {1,-7,15,-9};

    double a = -4.358899,b = 4.358899;
    int degree = 3;
    double h;
    int it = 0;

    double x1= a,x2 = a+ds, xr, err ;

    while(x2<b)
    {
        x1=a;
        x2 = a+ds;
    //    cout << "(" << x1 << " " << x2 << ") " ;

        if((func(poly,degree,x1)*func(poly,degree,x2))>0)
        {
           //   cout << "(w " << (func(poly,degree,x1)*func(poly,degree,x2)) << ") " ;

        }
        else
        {
            do
            {
                xr = (x1+x2)/2;

                if((func(poly,degree,x1)*func(poly,degree,xr))<0)
                {
                    x2 = xr;
                }
                else
                {
                    x1 = xr;
                }

                err = fabs((x2-x1)/x2);

            }
            while(err >= error);

            cout << xr << endl;

            if(x2>b)
                break;

        }
        a = x2;
    }

}


int main()
{

    allPossibleRoot();


    return 0;
}
