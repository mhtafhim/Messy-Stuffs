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

    double poly[] = {1,-5,-35,125,194,-280};
    double derivate[] = {5,-20,-105,250,194};
    double x = 3;
    int degree =  5;
    double h;


    do
    {
        if(func(derivate,2,x)==0)
        {
            cout << "math error" << endl;
            return 0;
        }

        h = x - func(poly,3,x)/func(derivate,2,x);
      //  cout << h << endl;

        x = h;
    }while (fabs(func(poly,3,x)) >= 0.0000001);

    cout << "The value of the root is : " << x << endl;
 //   cout << func(poly,3,x) << endl;


    return 0;
}
