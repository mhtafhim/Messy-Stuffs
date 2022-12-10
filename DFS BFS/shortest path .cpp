#include <bits/stdc++.h>

using namespace std;


struct node
{
    int value;
    node *next;

    node()
    {
        value = 0;
        next = NULL;
    }
    node(int x)
    {
        value = x;
        next = NULL;
    }
};

node* head;

void printLinkedList()
{
    cout << endl ;
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp-> next;

    }
    cout << endl;
}


void insertFirst(int x)
{


    node* newNode = new node(x);
    newNode->next = head;
    head = newNode;
}







int cost[10000];



//int n; // number of vertices

vector<bool> visited(10000,false);

void dfs(vector<int> adj[],int n,int v) {
    visited[v] = true;

    for (int u : adj[v]) {
        if (!visited[u])
            dfs(adj,n,u);

    }
    insertFirst(v);
    cout << v << " ";
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

  dfs(graph,v,1);

  printLinkedList();

  //  cout <<cost[x] << endl;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    head = NULL;
    int t;
    t=1;
//   cin >> t;
    while(t--)
    {

        solve();

    }


    return 0;
}

