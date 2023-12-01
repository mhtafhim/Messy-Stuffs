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
    vector<vector<ll>> v(n);
    bool ok = true;
    ll mn = 1e18;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    vector<ll> ansv;
    ll ans = 1 << 31;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ans = v[i][n - 1];
        else
            ans = v[i][0];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                ans &= v[i][j];
        }
        ansv.push_back(ans);
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if ((ansv[i] | ansv[j]) != v[i][j])
                {
                    //    cout << (ll)(ansv[i] | ansv[j]) << " ";
                    ok = false;
                }
            }
        }
    }

    if (!ok)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (auto a : ansv)
            cout << a << " ";
        cout << endl;
    }
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
