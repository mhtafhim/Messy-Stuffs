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

    for (int i = 0; i < n; i++)
        cin >> v[i];

    map<ll, vector<ll>> mp;

    for (ll i = 0; i < n; i++)
    {
        mp[v[i]].push_back(i);
    }

    ll cnt = n;
    ll up = n - 1;
    ll last = 0;

    //    cout << cnt << endl;

    // for (auto x : mp)
    // {
    //     cout << x.first << endl;
    //     for (auto y : x.second)
    //         cout << y << " ";
    //     cout << endl;
    // }

    // cout << endl
    //      << endl;

    for (auto a : mp)
    {

        ll upper = upper_bound(a.second.begin(), a.second.end(), up) - a.second.begin();
        // if(upper != 0)
        // cout << "upper =";
        cout << cnt << " ";
       cout << a.second[upper-1] << endl;
        if (a.second[upper-1] > 0)
        {
            cnt -= upper -1 - (a.first - last - 1);
            up = a.second[0] - 1;
            last = a.first;
        }
        else
        {
            break;
        }
    }

    //   cout << "ans  = ";
    cout << min(n, cnt) << endl;
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
 
/*
5 3 3 5 2 4 5 2 1



1

4 2 2 4 1 3 4 1 0

1

3 1 1 3 0 2 3 0 0

1

2 0 0 2 0 2 3 0 0


1 2 3 3 3 3 5

*/
