#include <bits/stdc++.h>

using namespace std;

int cost[10000];



int bfsOfGraph(int V, vector<int> adj[],int i)
{
    for(int i=0; i<=V; i++)
    {
        cost[i]=0;

    }
    int maximum=0;
    // vector<int> bfs_traversal;
    vector<bool> vis(V, false);



    // To check if already visited
    if (!vis[i])
    {
        queue<int> q;
        vis[i] = true;
        //  cost[i]++;
        q.push(i);

        // BFS starting from ith node
        while (!q.empty())
        {
            int g_node = q.front();
               cout << g_node << " ";
            q.pop();
            //      bfs_traversal.push_back(g_node);
            for (auto it : adj[g_node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    cost[it] = cost[g_node] +1;
                    //   cout << "cost =" << cost[it] << " " << it <<"maximum "<< maximum << endl;


                    //    cout << "cost =" << cost[it] << " " << it <<"maximum "<< maximum << endl;
                    q.push(it);
                }
            }
        }
    }

    for(int i =0;i <=V; i++)
    {
        if(cost[maximum]<cost[i])
            maximum = i;
    }


    return maximum;
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
        graph[v].push_back(u);
    }

    int x = bfsOfGraph(v,graph,1);
  //  int y = bfsOfGraph(n,graph,x);

    cout <<cost[x] << endl;
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
