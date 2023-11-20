#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18
 
vector<pair<ll, ll>> G[1000000];
bool vis[10000000];
vector<ll> dis(10000000, LLONG_MAX);
int h;
 
void dijktra(int v)
{
 
    priority_queue<pair<ll, ll>> pq;
    // vis[v] = true;
   
    pq.push({0, v});
 
    while (!pq.empty())
    {
       
        ll x = pq.top().second;
 
        //   cout << x << " " << pq.top().first << endl;
        pq.pop();
        //   int w = -x.first;
        // vis[x] = true;
 
        if (!vis[x])
        {
            vis[x] = true;
 
            for (auto u : G[x])
            {
                if (!vis[u.first] && (ll)(dis[x] + u.second) < dis[u.first])
                {
                    dis[u.first] = (ll)(dis[x] + u.second);
                    pq.push({(-1) * (ll)(dis[x] + u.second), u.first});
                    
                }
            }
        }
    }
}
 
void solve(int cs)
{
 
    int v, e;
    cin >> v >> e;
    h  = v;
 
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
 
        G[u].push_back({v, w});
      //  G[v].push_back({u, w});
    }
 
    dis[1] = 0;
    dijktra(1);
 
    for (int i = 1; i <= v; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
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