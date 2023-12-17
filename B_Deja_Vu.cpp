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
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n), x(q);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
    }

    //  vector<vector<pair<ll, ll>>> cnt(31);
    ll mn = 1e18;

    for (int i = 0; i < q; i++)
    {
        if (mn > x[i])
        {
            mn = x[i];
            ll tmp = 1LL << x[i];
            for (int j = 0; j < n; j++)
            {
                if (a[j] % tmp == 0)
                {
                    // cout << a[j] << " " << tmp << " " << i << endl;
                    a[j] += (tmp / 2);
                }
            }
        }
    }

    for (auto u : a)
        cout << u << " ";
    cout << endl;
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
