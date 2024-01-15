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
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n), vv(m);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> vv[i];

    ll first = 0, last = m - 1;
    ll sum = 0;

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    ll l = 0, r = n - 1;

    while (l <= r)
    {
      //  cout << l << " " << r << endl;
        ll diff1 = 0, diff2 = 0;
        ll f1 = -1, f2 = -1;
        if (abs(v[l] - vv[first]) >= abs(v[l] - vv[last]))
        {
            diff1 = abs(v[l] - vv[first]);
            f1 = 0;
        }
        else
        {
            diff1 = abs(v[l] - vv[last]);
            f1 = 1;
        }

        if (abs(v[r] - vv[first]) >= abs(v[r] - vv[last]))
        {
            diff2 = abs(v[r] - vv[first]);
            f2 = 0;
        }
        else
        {
            diff2 = abs(v[r] - vv[last]);
            f2 = 1;
        }

        if (diff1 > diff2)
        {
            //   cout << diff1 << " " << f1 << endl;
            sum += diff1;
            l++;
            if (f1 == 0)
                first++;
            else
                last--;
        }
        else
        {
            //     cout << diff2 << " " << f2 << endl;
            sum += diff2;
            r--;
            if (f2 == 0)
                first++;
            else
                last--;
        }
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
