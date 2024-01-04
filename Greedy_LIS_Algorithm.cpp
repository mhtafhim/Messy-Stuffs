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

    if (n == 1 && k == 0)
    {
        cout << 1 << endl;
        return;
    }

    if (n - 2 >= k)
    {
        int cnt = 1;
        for (int i = 1; i <= n - k - 2; i++, cnt++)
            cout << i << " ";
        cout << n << " ";
        for (int i = cnt; i <= n - 1; i++)
            cout << i << " ";

        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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
