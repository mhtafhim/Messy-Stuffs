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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<ll> suff(n), mx(n);

    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] += suff[i + 1] + a[i];
    }

    mx[0] = b[0];

    for (int i = 1; i < n; i++)
    {
        mx[i] = max(mx[i - 1], b[i]);
    }

     ll ans = 0;

    if(k >= n)
    {
        ans = suff[0] + (k-n)* mx[n-1];
    }
    else
    {
         ans =suff[0] - suff[k];
    }
   
  //  cout  <<  suff[0]  << endl;
// cout << ans << " " << k-n << "  " ;
//  cout << mx[n-1] << endl;
    for(int i = min(k,n) -1 ; i >=1 ; i --)
    {
        // cout << suff[0] - suff[i] << " "<< (k-i)<<  " * "<< mx[i-1] << " ";
        // cout << suff[0] - suff[i] + (k-i) * mx[i-1] << " -- " << endl;
        ans = max(ans,suff[0] - suff[i] + (k-i) * mx[i-1]);
    }

    cout << ans  << endl;

   
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
