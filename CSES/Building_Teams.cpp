#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

bool vis[10000000];
int team[10000000];
int parent[10000000];
vector<int> G[10000000];

bool possible = false;

void dfs(int u, int p = 0)
{
    for (int v : G[u])
    {
        if (v != p)
        {
            if (!vis[v])
            {
                team[v] = !team[u];
                vis[v] = true;
                dfs(v, u);
            }
            else if (team[v] == team[u])
                possible = false;
        }
    }
}

void solve(int cs)
{
    int n, m;

    cin >> n >> m;

    //   set<int> set1,set2;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
possible=true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i]= true;
            dfs(i);
        }
            
    }

    if(!possible)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int i= 1 ; i <= n ; i ++)
        {
            cout << (team[i] ? 2 : 1 ) << " ";
        }
        cout << endl;
    }
}

int main()
{
    fast;
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
