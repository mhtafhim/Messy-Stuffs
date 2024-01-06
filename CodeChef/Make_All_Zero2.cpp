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

    vector<ll> v(n), trac(n), preff(n);
    ll min = 1e18;
    ll inx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll mn = v[0];
    ll last = 0;
    trac[0] = v[0];

    for (int i = 0; i < n; i++)
    {
        if (mn == v[i])
        {
            trac[last] = 0;
            trac[i] = v[i];
            last = i;
        }
        else if (mn > v[i])
        {
            trac[i] = v[i];
            last = i;
            mn = v[i];
        }
    }

    reverse(trac.begin(), trac.end());

    ll cnt = 0;

    if (trac[0] != 0 )
    {
        cnt = (trac[0] < n ? trac[0] : n);
      //  cnt = trac[0];
        preff[0] = trac[0];
    }
    

    bool ok = true;

    for (int i = 1, j = n - 1; i < n - 1; i++, j--)
    {
        if (trac[i] - preff[i - 1] >= j)
            ok = false;
        if (trac[i] != 0 and ok)
        {

            cnt += trac[i] - preff[i - 1];
            preff[i] = preff[i - 1] + (trac[i] - preff[i - 1]);
        }
        else
        {
            // if(cnt == 0)cnt++;
            preff[i] = preff[i - 1];
        }
    }
    preff[n - 1] = preff[n - 2];

    reverse(preff.begin(), preff.end());

    for (int i = 0; i < n; i++)
    {
        if (preff[i] != v[i])
            cnt++;
    }

    // for (auto x : trac)
    //     cout << x << " ";
    // cout << endl;

    // for (auto x : preff)
    //     cout << x << " ";
    // cout << endl;

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

// 5 3 3 5 2 4 5 2 1

// 5 0 3 0 0 0 0 2 1

// 1  2-1=1+1=2 2 2 2 2 3-2=1+2=3 3