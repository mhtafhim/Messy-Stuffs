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

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(),greater<ll>());

    ll limit = (n + 1) / 2;
    ll i = 0;
    ll sum = 0;

    for ( i = 0; i < limit; i++)
    {
      sum+=v[i];
    }

     for (; i < n; i++)
    {
      sum-=v[i];
    }



    cout << sum << endl;
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
