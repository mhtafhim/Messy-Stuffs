#include <bits/stdc++.h>

using namespace std;


unsigned long long int func(unsigned long long int N)
{
    if(N == 0)
        return 1;
    return func(N/2) + func(N/3);
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long int N;
    cin >> N;
   cout << func(N);

   return 0;

}

