
#include <bits/stdc++.h>

using namespace std;


vector<int> ans;
vector<bool>visited(10000,false);
vector<bool>recStack(10000,false);
int countCycle = 0;



void dfs(vector<int> adj[],int n,int v)
{
    visited[v] = true;
    recStack[v] = true;

    for (auto u : adj[v])
    {
        if (!visited[u])
            dfs(adj,n,u);
        else if(recStack[u])
        {
             countCycle++;
             cout  << u << " " << v << endl;
        }


    }
    recStack[v] = false;
}

void solve()
{
    int v,e;
    cin >> v>>e;
    vector<int>graph[v+1];
    for(int i =0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        //    graph[v].push_back(u);
    }

    //  int x = bfsOfGraph(v,graph,1);
    //  int y = bfsOfGraph(n,graph,x);

    visited.assign(v,false);
    recStack.assign(v,false);

    for(int i=0; i<v; i++)
    {

        if(!visited[i])
            dfs(graph,v,i);

    }


    cout << endl << countCycle << endl;



    /*
      for(int it: ans)
      {
      	cout << it << " ";
      }
      cout << endl;

      */



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

