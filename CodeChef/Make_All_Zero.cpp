#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

void solve(int cs)
{

    ll n;
    cin >> n;

    vector<ll> v(n), trac(n), preff(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll val = 1e9;
    vector<ll> dec;

    ll ans = n;

    for (auto &x : v)
    {
        val = min(val, x);
        if (val == x)
            dec.push_back(x);
    }

    reverse(dec.begin(), dec.end());


    for (int i = 0; i < dec.size(); i++)
    {

   
        ans = min(ans, n - (i + 1) + dec[i]);
    }

    cout << ans << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}

// 5 3 3 5 2 4 5 2 1

// 5 0 3 0 0 0 0 2 1

// 1  2-1=1+1=2 2 2 2 2 3-2=1+2=3 3