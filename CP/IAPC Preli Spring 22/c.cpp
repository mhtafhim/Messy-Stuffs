#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define memset(v,x) memset((v),x,(sizeof(v)))
using namespace std;
typedef long long int lli;
const lli mod=1000000007;
bool vis[1000000];


int bfs(vector<int> adj[],int v)
{
    int maximum = -1;
    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int n = q.front();
        if(maximum < n)
        {
            maximum = n;
        }
        q.pop();

        if(!vis[n])
        {
            vis[n] = true;

            for(auto u : adj[n])
            {
                if(!vis[u])
                {
                    q.push(u);
                }
            }
        }

    }

    return maximum;
}




int main()
{

    fast

    lli t,n,i,x,mx,mn,f,j,s,r,y,c,m,k,z;
    t=1;
 //   cin >> t;
    for(int tc =1;tc<=t;tc++)
    {

        cin >> n>>m;
        int w[n+1];
        vector<int,int> adj[];

        for(int i =1; i<=n;i++)
        {
            cin >> w[i];
        }

        for(int j = 1 ; j<=m ; j++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }







    }


   return 0;
}
