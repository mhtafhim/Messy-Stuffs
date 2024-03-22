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
    bool flag = true;
    ll cnt = 0;
    ll mn = 1e18 , mx = 0;
    for (ll i = 0; i < n; i++)
    {
        if(ss[i] == 'B')
        {
            mn  = min(mn,i);
            mx = max(mx,i);
        }
        
    }

    cout << mx - mn + 1 << endl;
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
