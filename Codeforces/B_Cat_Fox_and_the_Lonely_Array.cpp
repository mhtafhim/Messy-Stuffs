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

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    ll l = 1, r = n, mid;

    ll ans = 0;

    while (l <= r)
    {
        mid = (l + r) / 2;
        ll tmp = 0;
        bool ok = true;
        ll tmp2 = 0;

        for (int j = 0; j < mid; j++)
        {
            tmp2 |= v[j];
        }

        for (int i = 0; i < n - mid + 1; i++)
        {
            tmp = 0;
            for (int j = 0; j < mid; j++)
            {
                tmp |= v[i + j];
            }
            if (tmp2 != tmp)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
        // cout << cs << " = " << st.size() << " " ;
        // cout << mid << endl;
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
