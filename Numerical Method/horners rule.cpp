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
    int x = 3;
    int degree =  3;

    cout << func(poly,degree,x);


    return 0;
}
