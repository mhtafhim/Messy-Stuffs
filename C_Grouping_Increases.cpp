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

    vector<ll> v(n), a, b;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll s = v[0], t = -1;
    ll cnt = 0;

    // if (n > 1)
    //     t = v[1];

    for (int i = 1; i < n; i++)
    {
        if (s >= t)
        {
            if (t >= v[i])
            {
                t = v[i];
            }
            else
            {
                if (s >= v[i])
                {
                    s = v[i];
                }
                else if (t == -1)
                    t = v[i];
                else
                {
                    cnt++;
                    s = v[i];
                }
            }
        }
        else
        {
            if (s >= v[i])
            {
                s = v[i];
            }
            else
            {
                if (t >= v[i])
                {
                    t = v[i];
                }
                else if (t == -1)
                    t = v[i];
                else
                {
                    cnt++;
                    t = v[i];
                }
            }
        }
    }

    cout << cnt << endl;
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




