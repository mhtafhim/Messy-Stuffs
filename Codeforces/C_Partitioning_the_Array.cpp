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
    set<int> div;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = v[i] % 2;
        //    cout << v[i] << " ";
    }
    // cout << endl;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int tmp = n / i;
            div.insert(tmp);
            div.insert(n / tmp);
        }
    }

    ll cnt = 0;

    for (auto u : div)
    {
      //  cout << u << " -- ";
        vector<int> vv;
        for (int i = 0; i < u; i++)
            vv.push_back(v[i]);

        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            if (v[i] != vv[i % u])
            {
                ok = false;
            }
        }
    //    cout << ok << endl;
        if (ok)
            cnt++;
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
