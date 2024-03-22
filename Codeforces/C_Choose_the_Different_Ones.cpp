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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    set<ll> sta, stb;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sta.insert(a[i]);
    }

    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
        stb.insert(b[i]);
    }

    //   sort(a.begin(), a.end());
    //   sort(b.begin(), b.end());

    ll tmp = k / 2;

    vector<ll> v;

    bool ok = true;
    ll reserve = 0;
    ll cnta = 0, cntb = 0;

    for (int i = 1; i <= k; i++)
    {

        if (sta.count(i) and stb.count(i))
        {
            reserve++;
        }
        else if (sta.count(i) and cnta < tmp)
        {
            cnta++;
        }
        else if (stb.count(i) and cntb < tmp)
        {
            cntb++;
        }
        else
        {
            ok = false;
            break;
        }
    }

   // cout << cnta + cntb + reserve << " ";
    if(cnta + cntb + reserve == k and ok)cout << "YES" << endl;
    else cout << "NO" << endl; 

  //  cout << ok << endl;
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
