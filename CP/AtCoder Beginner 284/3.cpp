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

 vector<bool> vis(200,false);
 lli counter =0;


void bfs(vector<int> adj[],int v)
{

    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int n = q.front();
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
        vector<int> adj[n+1];

        lli u,v;
        for(i =1;i<=m;i++)
        {
            cin >> u>> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        for(j=1;j<=n;j++)
        {
            if(!vis[j])
            {
                counter++;
                bfs(adj,j);
            }
        }

        cout << counter << endl;



    }


   return 0;
}
