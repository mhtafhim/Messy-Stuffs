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

    vector<ll> v(n);
    for(int i =0 ; i <n ; i ++)cin >> v[i];
    ll cnt = 0;
    ll mn = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] <= mn)
        {
            mn = min(mn, v[i]);
            continue;
        }
        else
        {
            cnt += (v[i]-1)/mn;

           // ll half = v[i] / 2;

            mn = v[i] / ( (v[i]-1)/ mn +1);
        }
    //    cout << "cnt = " << cnt << endl;
    }

    cout << cnt << endl;
}

int main()
{
    fast;
    int t = 1;
       cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
