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

    ll mx = 1;
    ll lim = n / k;
    for (ll i = lim; i >= 0; i--)
    {
        if (n % i == 0)
        {
            mx = max(mx,i);
            break;
        }
    }

    cout << mx << endl;
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
