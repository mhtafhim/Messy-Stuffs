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
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n), vv;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    ll dif = 1e18;

    if (k > 2)
        cout << 0 << endl;
    else if (k == 1)
    {
        dif = min(dif,v[0]);
        // ll dif = 1e18;
        for (int i = 0; i < n - 1; i++)
        {
            dif = min(dif, abs(v[i] - v[i + 1]));
        }

        cout << dif << endl;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            dif = min(dif, v[i]);
            for (int j = i+1; j < n; j++)
            {
                ll diff = abs(v[i] - v[j]);
                int inx = lower_bound(v.begin(), v.end(), diff) - v.begin();
                dif = min(dif,diff);
                dif = min(dif, abs(diff - v[inx]));
                 if ((inx - 1) >=0)
                    dif = min(dif, abs(diff - v[inx - 1]));
               
            }
        }

        cout << dif << endl;
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
