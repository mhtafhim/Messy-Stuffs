#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

vector<pair<int, int>> v(1000000);
string s;
int cost[1000000];
int mn = 1e9;

void dfs(int u, int cst)
{
    if (v[u].first == 0 and v[u].second == 0)
    {
        
        mn = min(mn, cst);
        return;
    }
 //   cout << u << " ";
  //  cout << v[u].first << " " << v[u].second << endl;

    if (s[u-1] == 'L' and v[u].first != 0)
        dfs(v[u].first, cst);
        
    if (s[u-1] == 'R' and v[u].second != 0)
        dfs(v[u].second, cst);

    if ((s[u-1] == 'R' || s[u-1] == 'U') && v[u].first != 0)
        dfs(v[u].first, cst + 1);

    if ((s[u-1] == 'L' || s[u-1] == 'U') && v[u].second != 0)
        dfs(v[u].second, cst + 1);
 
}

void solve(int cs)
{
  //  v.assign(v.size(),{0,0});
    mn = 1e9;

    int n;
    cin >> n;


    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        x, y;
        v[i] = {x, y};
        
    }


    dfs(1, 0);

    cout << mn << endl;
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
