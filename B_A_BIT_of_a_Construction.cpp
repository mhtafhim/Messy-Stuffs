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

    ll x = 1;

    for (int i = 1; i < 35; i++)
    {
        if (x <= k)
            x = x << 1;
        else
            break;
    }

    x = x / 2 - 1;

    if (n == 1)
    {
        cout << k << " ";
    }
    else
    {
        cout << x << " " << k - x << " ";
        for (int i = 0; i < n - 2; i++)
            cout << 0 << " ";
    }

    cout << endl;
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
