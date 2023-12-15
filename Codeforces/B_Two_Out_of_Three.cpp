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
    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &x : v) cin >> x ;

    vector<vector<int>> cnt(101);

    for (int i = 0; i < n; i++)
    {
        cnt[v[i]].push_back(i);
    }

    vector<int> bla;
    int cntt = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (cnt[i].size() >= 2)
        {
            cntt++;
            bla.push_back(cnt[i][0]);
        }
    }

    vector<int> ans(n,1);

    if(cntt >= 2)
    {
        ans[bla[0]] = 2;
        ans[bla[1]] = 3;

        for(auto x : ans ) cout << x << " " ;
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }


   
}

// 1 2 1 1 3 1 1 1 1

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
