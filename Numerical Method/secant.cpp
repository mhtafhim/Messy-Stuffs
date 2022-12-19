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
    double x0=2,x1=4,x2,f0,f1,f2;
    int degree =  3;



     do
	 {
		  f0 = func(poly,3,x0);
		  f1 = func(poly,3,x1);


		  x2 = x1 - (x1 - x0) * f1/(f1-f0);

		  f2 = func(poly,3,x2);

		  x0 = x1;
		  x1 = x2;



	 }while(fabs(f2)> 0.0000001);


    cout << "The value of the root is : " << x2 << endl;
    cout << func(poly,3,x2) << endl;


    return 0;
}
