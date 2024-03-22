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

    map<ll, ll> mp;

    for (int i = 0; i < n; i++)
    {
        ll sum = v[i];
        mp[sum]++;
        for (int j = i - 1, k = 0; j >= 0 and k < 500; j--,k++)
        {
            sum += v[j];
            mp[sum]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << mp[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    int t = 1;
        cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
