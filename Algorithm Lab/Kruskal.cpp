#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

#define pr pair<int,int>

vector<int> parent(10000);
vector<pair<int,pair<int,int>>> mst;


int find_set(int i)
{

    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void union_set(int u, int v)
{
    parent[u] = parent[v];
}

void kruskal(vector<pair<int,pair<int,int>>> adj)
{
    int i, uRep, vRep;

    sort(adj.begin(), adj.end());

    for (i = 0; i < adj.size(); i++)
    {
        uRep = find_set(adj[i].second.first);
        vRep = find_set(adj[i].second.second);

        if (uRep != vRep)
        {
            mst.push_back({adj[i].first,{adj[i].second.first,adj[i].second.second}});  // add to tree
            union_set(uRep, vRep);

        }
    }

}

void printTree(int v)
{
    for(int i =0; i<v-1; i++)
    {
        cout << mst[i].second.first << " - " << mst[i].second.second << "  and Weight = " << mst[i].first << endl;
    }
}

int main()
{
    int v,e;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the number of edges : ";
    cin >>e;
    int s,d,w;
    cout << "Now enter all the edges and weights (with separated space) : \n";
    vector<pair<int,pair<int,int>>> adj;

    for(int i =0; i<e; i++)
    {
        cin >> s>>d>>w;
        adj.push_back({w,{s,d}});
    }

    for(int i =0; i<=v; i++)
    {
        parent[i] = i;
    }


    kruskal(adj);

    printTree(v);


    return 0;
}
