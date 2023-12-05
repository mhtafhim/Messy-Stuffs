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

    vector<pair<ll, ll>> vpr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vpr[i].first >> vpr[i].second;
    }

    ll mx = 0;

    ll l = 0, h = 1e9, mid;
    ll ans = 0;

    while (l <= h)
    {
        mid = (l + h) / 2;

        ll start, end;
        bool ok = true;

        if ((0 + mid) >= vpr[0].first)
        {
            start = vpr[0].first;
            end = min(mid , vpr[0].second);
        }
        else
        {
            ok = false;
        }

        for (int i = 1; i < n; i++)
        {
            ll tmp1 = start - mid;
            ll tmp2 = end + mid;
           
            if (tmp1 <= vpr[i].second)
            {
               start = max(tmp1 , vpr[i].first);
            }
            else
            {
                ok = false;
                break;
            }

            if (tmp2 >= vpr[i].first)
            {
                end = min(tmp2 , vpr[i].second);
            }
            else
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            h = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
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
