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
    ll n, m, k;

    cin >> n >> m >> k;

    if (k == 1)
        cout << 1 << endl;
    else if (k == 2)
    {
        if (m <= n)
            cout << m << endl;
        else
            cout << n + max(0ll, (m / n - 1)) << endl;
    }
    else if (k == 3)
    {
        if (m <= n)
            cout << 0 << endl;
        else
            cout << m - (n + max(0ll, (m / n - 1))) << endl;
    }
    else
        cout << 0 << endl;
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
