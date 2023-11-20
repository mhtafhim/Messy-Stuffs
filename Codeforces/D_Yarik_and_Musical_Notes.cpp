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

    map<ll, ll> mp;

    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;

        if (tmp == 1)
        {
            cnt += mp[2];
            cnt += mp[1];
            mp[1]++;
            continue;
        }
        else if (tmp == 2)
        {
            cnt += mp[1];
            cnt+= mp[2];
            mp[2]++;
            continue;
        }

        if (mp.count(tmp))
        {
            cnt += mp[tmp];
        }
        mp[tmp]++;
    }

  

    cout << cnt << endl;
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
