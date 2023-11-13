#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1}; //4 Direction
int dp[1000][1000];
int grid[1000][1000];
bool visited[1000];
int H,W;

void reset()
{
    for(int i = 0 ; i < 1000 ; i ++)
    {
        visited[i] = false;
        for(int j = 0 ; j < 1000 ; j ++)
        {
            grid[i][j] = 0;

        }
    }
}

void dfs(int start)
{


  //  cout << start << endl;
    // Set current node as visited
    visited[start] = true;

    // For every node of the graph
    for (int i = 0; i < H; i++)
    {

        // If some node is adjacent to the current node
        // and it has not already been visited
        if (grid[start][i] == 1 && (!visited[i]))
        {
            dfs(i);
        }
    }
}



void solve(int cs)
{
    reset();
    //  int n,m;

    int v,e;
    cin >> v >> e;

    H = v, W = v;
    // char graph[n][m];

    for(int i =0 ; i< e ; i ++)
    {
        int a,b;
        cin >> a >> b ;
        grid[a][b] = 1;
        grid[b][a] = 1;

    }

      for(int i = 0 ; i< H ; i++)
    {
        grid[i][i] = 1;
    }








    int cnt = 0 ;



    for(int i =0 ; i< H ; i ++)
    {
        for(int j = 0 ; j < H ; j ++)

            if(!visited[j] && !visited[i] && grid[i][j] == 1)
            {
                cnt++;
                dfs(i);
            }
    }

    cout << cnt-1 << endl;




}

int main()
{
    fast;
    int t=1;
//    cin>>t;
    for(int i=1; i<=t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
