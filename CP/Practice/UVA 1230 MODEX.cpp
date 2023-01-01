#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
  //  cout << res << endl;
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {


        long long a,b,m;
        cin >>a>>b>>m;



        cout << binpow(a,b%(m-1),m)<< endl;


    }

    return 0;
}

