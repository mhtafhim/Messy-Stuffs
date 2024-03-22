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

    vector<ll> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    //  map<ll,ll> mp;

    vector<ll> aa, bb;

    ll x = 0, y = n - 1, ii, jj;
    for (ii = 0; ii < n; ii++)
    {
        for (; x < n; x++)
        {
            //  cout << b[ii] << " " << a[x] << endl;
            if (b[ii] == a[x])
            {
                aa.push_back(x);
                x++;
                break;
            }
        }
        if (x == n)
            break;
    }

    //  cout << "ii = ";
    //   cout << n - ii << endl;

    for (jj = n - 1; jj >= 0; jj--)
    {
        for (; y >= 0; y--)
        {
            //  cout << b[jj] << " " << a[y] << endl;
            if (b[jj] == a[y])
            {
                bb.push_back(y);
                y--;
                break;
            }
        }
        if (y == -1)
            break;
    }

    // cout << "jj = ";
    // cout << n - jj << endl;

    // for(auto u : aa)cout << u << " ";
    // cout<< endl;
    // for(auto u : bb)cout << u << " ";
    // cout<< endl;

    //  vector<ll> neww;

    reverse(aa.begin(), aa.end());

    ll current = -1;
    ll cnt = 0;
    if (bb.size() > 0)
    {
        current = bb[0];
        cnt = 1;
    }

    for (auto u : bb)
    {
        //   cout << u << endl;
        if (u < current)
        {
            //   cout << u << endl;
            cnt++;
            current = u;
        }
    }

    if (current == -1 and aa.size() > 0)
    {
        current = aa[0];
        cnt = 1;
    }

    for (auto u : aa)
    {
        //  cout << current << " " << u << endl;
        if (u < current)
        {
            //    cout << u << endl;
            cnt++;
            current = u;
        }
    }

    //  cout << aa.size() << " " << bb.size() <<  " " << cnt << endl;

    ll ans = max(aa.size(), bb.size());
    ans = max(ans, cnt);

    cout << n - ans << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
