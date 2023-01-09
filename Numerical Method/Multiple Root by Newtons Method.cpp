#include <bits/stdc++.h>

using namespace std;

void findDerivate(double arr[],double derivate[],int degree)
{
    int temp = degree;
    for(int i=0;i<degree;i++)
    {
       derivate[i] = arr[i]*temp;
       temp--;
    }
}

double func(double arr[],double degree,double x)
{

    double result = arr[0];

    for (int i=1; i<=degree; i++)
        result = result*x + arr[i];


    return result;

}

void syntheticDivision(double a[],double x,int n)
{
    double b[n];
    b[0] = a[0];

    for(int i =1; i<=n; i++)
    {
        b[i] = a[i] + x*b[i-1];
    }

    n--;

    for(int i =0; i<=n; i++)
    {
        a[i] = b[i];
    }

}



void allPossibleRoot()
{

    double poly[] = {1,-7,15,-9};
    double derivate[] = {3,-14,15};
    double x = 4;
    int degree =  3;
    double h;
    int it = 0;


    while(degree>1)
    {
        it++;

        do
        {
            if(func(derivate,degree-1,x)==0)
            {
                cout << "math error" << endl;
                return;
            }

            h = x - func(poly,degree,x)/func(derivate,degree-1,x);
        //    cout << h << endl;

            x = h;
        }
        while (fabs(func(poly,degree,x)) >= 0.00000001);

        cout << "root no "<< it <<": " << (double)x << endl ;


        syntheticDivision(poly,x,degree);
        degree--;

         findDerivate(poly,derivate,degree);

    }

    x = ((-1)*poly[1])/poly[0];

    cout << "root no "<< ++it <<": " << x << endl ;


}


int main()
{

    allPossibleRoot();


    return 0;
}

