
#include<bits/stdc++.h>

using namespace std;



double func(double arr[],double degree,double x)
{

    double result = arr[0];

    for (int i=1; i<=degree; i++)
        result = result*x + arr[i];


    return result;

}

void findDerivate(double arr[],double derivate[],int degree)
{
    int temp = degree;
    for(int i=0;i<degree;i++)
    {
       derivate[i] = arr[i]*temp;
       temp--;
    }
}



int main()
{

    double poly[] = {3,4,5};
    double derivate[] = {6,-12,2};
    double x = 3;
    int degree =  2;
    double h;

    findDerivate(poly,derivate,degree);

    for(int i=0;i<degree;i++)
    {
       cout << derivate[i] << "  ";
    }


//    cout << "The value of the root is : " << x << endl;
 //   cout << func(poly,3,x) << endl;


    return 0;
}
