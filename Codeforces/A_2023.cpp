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
    ll a, b;
    cin >> a >> b;

    vector<ll> v(a);
    ll product = 1;

    for (int i = 0; i < a; i++)
    {
        cin >> v[i];
        product *= v[i];
    }

    //  cout << product << endl << endl;

    if (product > 2023 || 2023 % product != 0)
    {
        cout << "NO" << endl;
    }
    else
    {

        cout << "YES" << endl;
        ll ans = 2023 / product;
        cout << ans << " ";
        for (int i = 1; i < b; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
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
