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

    string a, b, c;
    cin >> a >> b >> c;

    bool ok = true;

    for (int i = 0; i < n; i++)
    {
        if ((a[i] == b[i]) and (b[i] == c[i]) and a[i]==c[i])
            continue;
        else if ((a[i] == c[i] || b[i] == c[i]))
        {
      //      cout << c[i];
            ok = false;
        }
    }
   // cout << endl;

    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
