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
    ll n, k, d;

    cin >> n >> k >> d;

    vector<ll> v(n), vk(k);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < k; i++)
    {
        cin >> vk[i];
    }

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == i + 1)
            cnt++;
    }
    ans = max(ans, cnt + (d - 1) / 2);
  //  cout << ans << endl;

    for (ll i = 1; i < min((ll)4000,d); i++)
    {
        ll inx = ((i % k) == 0 ? k - 1 : (i % k) - 1);
        int open = 1;
        ll value = vk[inx];
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
        //    cout << ((value >= j + 1) * 1) << " ";
            v[j] = v[j] + ((value >= j + 1) * 1);
       //    cout << v[j] << " - ";
            if (v[j] == j + 1)
                cnt++;
        }
    //    cout << endl;
     //   cout  <<cnt  << endl;
        ans = max(ans, cnt + (d - i-1) / 2);
    }

    cout << ans << endl;
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
