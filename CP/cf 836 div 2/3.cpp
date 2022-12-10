#include <iostream>
#include<stdio.h>
using namespace std;


int main()
{


    int t;
    cin >> t;
    while(t--)
    {
        int number;
        cin >> number;
        if(number % 2 == 1)
        {
            for(int i = 0; i < number; i++)
            {
                printf("%d ",1);
             //   cout << 1 << " ";
            }
        }
        else
        {
            for(int i = 0; i < number - 2; i++)
            {
                printf("%d ",2);
             //   cout << 2 << " ";
            }

            printf("%d %d",1,2);
           // cout << 3 << " " << 1;
        }
        cout << endl;
    }
}

