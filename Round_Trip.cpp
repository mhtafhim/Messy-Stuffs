#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

vector<int> graph[100000];
vector<bool> vis(100000, false);
vector<int> parent(100000), cost(100000, 0);

int stop, par;
bool ok = true;

void dfs(int v)
{
    vis[v] = true;
    //    cout << v << " ";

    for (auto u : graph[v])
    {

        if (vis[u] && parent[v] != u && ok)
        {
            cout << endl;
            //  cout << vis[u] << " "<< v << " " << parent[v] << " " << u << endl;
            stop = u;
            parent[u] = v;
            par = v;
            ok = false;
        }

        if (!vis[u])
        {
         //   cout << vis[u] << " " << v << " " << parent[v] << " " << u << endl;
            parent[u] = v;
            cost[u] = cost[v] + 1;
            dfs(u);
        }
    }
}

void print(int v)
{

    cout << v << " ";
    if (stop == parent[v])
    {
        return;
    }
    print(parent[v]);
}

void solve(int cs)
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i] && ok)
        {
            parent[i] = -1;
            dfs(i);
        }
    }

    // cout << endl;

    // for (int i = 1; i <= v; i++)
    // {
    //     cout << parent[i] << " ";
    // }

    // cout << endl;
    // cout << stop << endl;
    // cout << endl;
    if (!ok)
    {
        cout << cost[par] - cost[stop] + 2 << endl;

        print(stop);
        cout << stop << " ";
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
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
