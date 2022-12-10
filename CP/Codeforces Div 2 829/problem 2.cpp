#include <iostream>
using namespace std;
void arrangeN(int N)
{
    if (N == 1)   //if N is 1, only that will be placed
    {
        cout << 1 ;
        return;
    }
    if (N == 2 || N == 3)   //for N = 2 and 3, no such permutation is available
    {
        for(int i =1; i<=N ; i++)
            cout << i << " ";
        cout<<endl;
        return;
    }
    int even_max = -1, odd_max = -1;
    //find max even and odd which are less than or equal to N
    if (N % 2 == 0)
    {
        even_max = N;
        odd_max = N - 1;
    }
    else
    {
        odd_max = N;
        even_max = N - 1;
    }
    while (odd_max >= 1)   //print all odd numbers in decreasing order
    {
        cout << odd_max << " ";
        odd_max -= 2;
    }
    while (even_max >= 2)   //print all even numbers in decreasing order
    {
        cout << even_max << " ";
        even_max -= 2;
    }
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int N ;
        cin>>N;
        arrangeN(N);
    }


}
