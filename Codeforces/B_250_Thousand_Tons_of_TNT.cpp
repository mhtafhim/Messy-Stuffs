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
    int n;
    cin >> n;

    vector<int> v;
    ll mx = -1e18;
    ll mn = 1e18;
    ll mmx = -1e18;
    ll mmn = 1e18;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
           mmn = min(mmn,tmp);
           mmx = max(mmx,tmp);
        sum += tmp;
        v.push_back(tmp);
    }

    ll ans = mmx - mmn;
  //  cout << ans << endl;

    for (int i = 1; i < n; i++)
    {
        mn =1e18;
        mx =-1e18;
        if (n % i == 0)
        {
            int interval = i ;
            ll sm = 0;
            for (int j = 0; j < n; j++)
            {
              

                    interval--;
                    sm += v[j];
             
                if(interval <=0 )
                {
                    mx = max(mx, sm);
                    mn = min(mn, sm);
               //     cout << i << "  " << interval << " sm = " << sm << endl;
                    interval = i ;
                    sm = 0;
                }
                
              
            }
         //   cout << mx << "-mx  &  mn-" << mn << endl;
            ans = max(ans, mx - mn);
        }
    }

    //  cout << mmx - mmn << endl;

    cout << ans << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
    //    cout << "Case " << i << ":\n";
        solve(i);
    }
    return 0;
}
