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

    ll n, q;
    cin >> n >> q;

    vector<ll> v(n), query(q);

    ll mx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > mx)
            mx = v[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }

    vector<ll> pref(mx + 1);
    int sz = v.size() - 1;

    for (int i = 0; i < n; i++)
    {
        pref[v[i]] += sz - i;
        pref[v[i]+1] -= i;
    }

    // for(int i =0 ; i < n-1 ; i++)
    // {
    //     for(int j = i+1; j < n ; j ++)
    //     {
    //         pref[v[i]]+=1;
    //         pref[v[j]+1]-=1;
    //     }
    // }

    for (int i = 1; i <= mx; i++)
    {
       // cout << pref[i] << " ";
        pref[i] += pref[i - 1];
    }

  //  cout << endl;

    sort(pref.begin(), pref.end());

    // for (int i = 1; i < pref.size(); i++)
    //     cout << pref[i] << " ";

    // cout << endl;

    for (int i = 0; i < q; i++)
    {
        int lower = lower_bound(pref.begin(), pref.end(), query[i]) - pref.begin();
        int upper = upper_bound(pref.begin(), pref.end(), query[i]) - pref.begin();

        cout << upper - lower << " ";
    }

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
