#include <bits/stdc++.h>

using namespace std;


vector<int> ans;
vector<bool>visited(10000,false);
vector<int> parent(1000);
vector<int> cost(1000,-1);

void DAG(vector<pair<int ,int >> adj[],int n,int v)
{
    for(int u : adj[v])
    {
        if(cost[])
    }


}



void dfs(vector<pair<int ,int >> adj[],int n,int v) {
    visited[v] = true;

    for (auto u : adj[v]) {
        if (!visited[u])
            dfs(adj,n,u);

    }
    ans.push_back(v);

}

void solve()
{
    int v,e;
    cin >> v>>e;
    vector<pair<int ,int >>graph[v+1];
    for(int i =0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    //    graph[v].push_back(u);
    }

  //  int x = bfsOfGraph(v,graph,1);
  //  int y = bfsOfGraph(n,graph,x);

  dfs(graph,v,1);

  reverse(ans.begin(),ans.end());

/*
  for(int it: ans)
  {
  	cout << it << " ";
  }
  cout << endl;

  */

  int source;
  cin >> source ;

  for(int i =0;i<=v;i++)
  {
      cost[i] = -1;
      parent[i] = -1;
      visited[i] = false;
  }
  cost[source] = 0;

    for(int it: ans)
  {
  	DAG(it);
  }



}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
//   cin >> t;
    while(t--)
    {

        solve();

    }


    return 0;
}

