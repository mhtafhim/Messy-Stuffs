
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

const int NMAX = 1e8;

void seive()
{

    vector<bool> bits(INT_MAX,true);

    vector<int> primes;

  //  bits.set();
    bits[0] = bits[1] = 0;
    primes.push_back(2);
    for (int i = 3; i <= NMAX; i += 2)
    {
        if (bits[i])
        {
            primes.push_back(i);
            if (i*(ll)i < (ll)NMAX)
            {
                for (int j = i * i; j <= NMAX; j += i)
                    bits[j] = 0;
            }
        }
    }

    for (int i = 0; i < primes.size(); i += 100)
        cout << primes[i] << endl;
}

void solve(int cs)
{

    seive();

    //  cout << primes[100] << endl;
}

int main()
{
    fast;
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
