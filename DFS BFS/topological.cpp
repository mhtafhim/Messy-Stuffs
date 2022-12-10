#include <bits/stdc++.h>

using namespace std;





int cost[10000];
int cnt = 0;
vector<int> ans;


//int n; // number of vertices

vector<bool> visited(10000,false);

void dfs(vector<int> adj[],int n,int v)
{
    visited[v] = true;
    cnt++;

    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(adj,n,u);

    }
    ans.push_back(v);

//   cout << v << " ";
}

void solve()
{
    int v,e;
    cin >> v>>e;
    vector<int>graph[v+1];
    for(int i =0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        //    graph[v].push_back(u);
    }

    //  int x = bfsOfGraph(v,graph,1);
    //  int y = bfsOfGraph(n,graph,x);

    for(int i = 1; i<=v; i++)
    {
        if(!visited[i])
            dfs(graph,v,i);

    }

    reverse(ans.begin(), ans.end());

    for(int i =0; i<ans.size(); i++)
    {
        cout << ans[i]<< " ";

    }


// cout << "Sandro fails." << endl;



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


