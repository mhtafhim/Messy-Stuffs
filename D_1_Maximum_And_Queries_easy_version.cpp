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
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    while (q--)
    {
        ll k;
        cin >> k;

        ll l = 0, h = 2e18, mid,mn;


        while (l <= h)
        {
            mid = (l + h) / 2;

           

            ll cnt = 0;
            for (auto u : v)
            {
                if (mid > u)
                {
                    //  cout << "if" << endl;
                    cnt += mid - u;
                }
                else
                {
                    //     cout << "else" << endl;
                    ll tmp = (u & mid);
                    if (tmp != mid)
                        cnt += (mid - (u % mid));
                }
                //    cout << u << endl;
            }
            cout << l << "  " << h << " -> ";
            cout << cnt << " " << mid << endl;

     

            if (cnt > k)
                h = mid - 1;
            else
            {
                l = mid + 1;
                mn = mid;
            }
        }

        cout << mn << endl;
    }
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
