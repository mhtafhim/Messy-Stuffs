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
    string ss;
    cin >> ss;

    vector<int> v(26);

    for (int i = 0; i < n; i++)
    {
        v[ss[i] - 'a']++;
    }
    int mx = 0;
    for (int i = 0; i < 26; i++)
    {
        mx = max(mx, v[i]);
    }
 //   cout << "mx = ";
 //   cout << mx << endl;

    if (mx <= n / 2)
    {
        if (n & 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    else
    {
        cout << 2 * mx - n << endl;
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
