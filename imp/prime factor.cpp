#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

std::vector<int> minp, primes;

void sieve(int n)
{
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes)
        {
            if (i * p > n)
            {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i])
            {
                break;
            }
        }
    }
}

void solve(int cs)
{
    sieve(10000000);

    int n;
    cin >> n;
    vector<int> factors;
    int tmp;
    while (n >1)
    {
        tmp = minp[n];
        factors.push_back(tmp);
        n/= tmp;
    }

    for(int i = 0 ; i < factors.size();i++)
    {
        cout << factors[i] << " " ;
    }
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
