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
    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> v(n), preff(n + 1), suff(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
            preff[i] = v[i];
        else
            preff[i] = preff[i - 1] + v[i];
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
            suff[i] = v[i];
        else
            suff[i] = suff[i - 1] + v[i];
    }

    ll ans = -1e18;
    for (int i = 0; i <= k; i++)
    {
        ll sum = 0;
        int inx = min(x - 1 + i , n-1);
        if (i == 0)
             sum = suff[inx];
        else
             sum = suff[inx] - suff[i-1];

        // cout << i << " " << suff[inx] << " " <<suff[i-1] << " " << sum << " " ;
        // cout << preff[n - 1 - i] << " ";
        if (i == n)
            ans = max((ll)0, ans);
        else
            ans = max(ans, preff[n - 1 - i] - 2 * sum);
     //   cout << ans << endl;
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
