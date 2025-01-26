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
    ll a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    ll ans = a;

    while (a > 0)
    {
        if (c > b)
        {
            a--;
            c--;
        }
        else
        {
            a--;
            b--;
        }
    }

    ans += min(b, c);

    cout << ans << endl;

    return;
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
