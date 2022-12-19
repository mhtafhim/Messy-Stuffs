#include<bits/stdc++.h>

using namespace std;



double func(double arr[],double degree,double x)
{

    double result = arr[0];

    for (int i=1; i<=degree; i++)
        result = result*x + arr[i];


    return result;

}



int main()
{

    double poly[] = {2, -6, 2, -1};
    double derivate[] = {6,-12,2};
    double x = 3;
    int degree =  3;
    double h;


    do
    {

         x1 = func(poly,3,x0);


		  x0 = x1;

    }while (fabs(func(poly,3,x)) >= 0.0000001);

    cout << "The value of the root is : " << x << endl;
 //   cout << func(poly,3,x) << endl;


    return 0;
}
