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

    vector<pair<ll, ll>> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    vector<pair<ll, ll>> head(n);

    for (ll i = 0; i < n; i++)
    {
        head[i].first = (v[i].first - v[i].second);
        head[i].second = i;
    }

    sort(head.begin(), head.end());

    pair<ll, ll> x = head[0];

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == x.second)
            ans += v[i].second;
        else
            ans += v[i].first;
    }

    cout << ans << endl;
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
