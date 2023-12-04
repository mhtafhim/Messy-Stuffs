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
    ll n, p, tt, t;
    cin >> n >> p >> tt >> t;

    ll l = 0, h = n, mid;
    ll week = (n - 1) / 7 + 1;
    ll ans;

    while (l <= h)
    {
        mid = (l + h) / 2;
        //   cout << mid << endl;

        ll point = (n - mid) * tt;
        if (n - mid > week)
            point += week * t;
        else
        {
            ll tmp = 2 * (n-mid);
            if(tmp > week)
            {
                point += week * t;
            }
            else
            {
                point += tmp * t;
            }
            
        }

     //   cout << l << " " << h << " " << point << " " << mid << endl;

        if (point >= p)
        {
            l = mid + 1;
            ans = mid;
        }

        else
        {
            h = mid - 1;
           // ans = mid;
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
