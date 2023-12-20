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

    vector<ll> x(n), y(n);

    for (auto &z : x)
        cin >> z;
    for (auto &z : y)
        cin >> z;

    vector<pair<ll, ll>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({x[i] + y[i], i});
    }

    sort(v.rbegin(), v.rend());
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            ans -= y[v[i].second] - 1;
        }
        else
        {
            ans+= x[v[i].second] -1;
        }
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
