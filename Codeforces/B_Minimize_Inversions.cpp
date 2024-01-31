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

    vector<pair<ll,ll>> v(n), sum(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        sum[i].first = v[i].first + v[i].second + abs(v[i].first - v[i].second);
        sum[i].second = i;
    }

    sort(sum.begin(), sum.end());

    for (int i = 0; i < n; i++)
    {
        cout << v[sum[i].second].first << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[sum[i].second].second << ' ';
    }

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
