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
    ll x, y;
    cin >> x >> y;

    ll mn = min(x, y);
    ll mnn = min(mn,abs(x-y));
    ll mx = max(x, y);

    ll tmp = mn;
    ll tmp2 = mx;
    ll ans = mn;

    while(tmp > 0)
    {
        ans = tmp;
        tmp = tmp2%tmp;
        tmp2 = ans;
      //  cout << tmp << " " << tmp2 << endl;
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
