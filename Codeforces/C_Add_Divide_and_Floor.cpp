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
    vector<ll> v(n),anss;
    ll mn = inf;
    ll mx = -inf;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    ll gap = mx - mn;
    // cout << gap << endl;
    if(gap == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = log2(gap) +1 ;

    cout << ans << endl;

    if(ans <=n)
    {
   //     cout << mn << " " << mx << endl;
        for (int j = 0; j < ans; j++)
        {
             if (mn & 1)
            {
                cout << 1 << " ";
                mn++;
                mx++;
               
            }
            else
            {
                cout << 0 << " ";
            }
         
             mn /= 2;
             mx /= 2;

      //      cout << mn << " " << mx << endl;
        }
      
     //   cout << endl;
     //   cout << mn << " " << mx << endl;
   

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
