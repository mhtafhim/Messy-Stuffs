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
    vector<int> v;
    int cnt = 0;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == '#')
        {
            if (cnt > 0)
                v.push_back(cnt);
            mx = max(mx, cnt);
         //   cout << "cnt = " << cnt << endl;
            cnt = 0;
        }
        else
        {
            cnt++;
        }
        // cin >> v[i];
    }

    if (cnt > 0)
        v.push_back(cnt);
    mx = max(mx, cnt);
   // cout << "cnt = " << cnt << endl;
    cnt = 0;

    sort(v.rbegin(), v.rend());
    int ans = 0;
    if (mx > 2)
    {
        cout << 2 << endl;
    }
    else
    {

        int ans = 0;
        for(auto u : v) ans += u;
        cout << ans << endl;
    }
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
