#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

char adj[1000][1000];
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction D L U R
int dp[1000][1000];
char grid[1000][1000];
bool visited[1000][1000];
map<pair<int,int>,pair<int,int>> parent;
map<pair<int,int>,char> mp;
int H,W,cnt;

stack<pair<int,int>> stk;
bool ok = false;

void bfs(int a,int b)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
   // vector<bool> visited(adj.size(), false);
    queue<pair<int,int>> q;
    q.push({a,b});
  
    // Set source as visited
    visited[a][b] = true;

    parent[{a,b}] = {-1,-1};
  
    
    while (!q.empty()) {

        auto vis = q.front();
        q.pop();
        int x = vis.first , y = vis.second;
  
        // Print the current node
      //  cout << vis << " ";
      //  q.erase(q.begin());
   //     cout << '(' << x << ',' << y << ')' ;
  
        // For every adjacent vertex to the current vertex
        for (int i = 0; i < 4; i++) {
            if(grid[x+ dx[i]][y+ dy[i]] == 'B')
            {

                if(i == 0)mp[{x+ dx[i],y+ dy[i]}]= 'D';
                else if(i == 1 ) mp[{x+ dx[i],y+ dy[i]}]= 'R';
                else if(i == 2 ) mp[{x+ dx[i],y+ dy[i]}]= 'U';
                else if(i == 3 ) mp[{x+ dx[i],y+ dy[i]}]= 'L';

              //  cout <<  << endl;
                cnt = dp[x][y]+1;
              //  cout << '(' << x+ dx[i] << ',' << y+ dy[i] << ')' ;
                stk.push({x+ dx[i],y+ dy[i]});

                pair<int,int> pr;
                pr = {x,y};
                while(pr.first != -1 && pr.second != -1)
                {
                    stk.push(pr);
                    pr = parent[{pr.first,pr.second}];
                }
                ok = true;
                return;
            }
            else if (!visited[x+ dx[i]][y+ dy[i]] && '.' == grid[x+ dx[i]][y+ dy[i]]  && (x + dx[i]) < (H) && (x+ dx[i]) >=0 &&(y + dy[i]) < (W) && (y + dy[i]) >= 0 ) {
  
                // Push the adjacent node to the queue
                q.push({x+ dx[i],y+ dy[i]});
                dp[x+ dx[i]][y+ dy[i]] = dp[x][y] + 1;
                parent[{x+ dx[i],y+ dy[i]}] = {x,y}; //D L U R

                if(i == 0)mp[{x+ dx[i],y+ dy[i]}]= 'D';
                else if(i == 1 ) mp[{x+ dx[i],y+ dy[i]}]= 'R';
                else if(i == 2 ) mp[{x+ dx[i],y+ dy[i]}]= 'U';
                else if(i == 3 ) mp[{x+ dx[i],y+ dy[i]}]= 'L';
                // Set
                visited[x][y] = true;
            }
        }
    }

   
   
}
  


void solve(int cs){

     cin >> H >> W;
   // char graph[n][m];

    for(int i =0 ; i< H ; i ++)
    {
        for(int j = 0 ; j< W ; j++)
        {
            cin >> grid[i][j];
        }
    }

      for(int i =0 ; i< H ; i ++)
    {
        for(int j = 0 ; j< W ; j++)
        {
            if( grid[i][j] == 'A'){
              //  cnt++;
                bfs(i,j);
            }
        }
    }


if(ok){
    cout << "YES" << endl;
    cout << cnt << endl;
    stk.pop();
    while(!stk.empty())
    {

        cout << mp[stk.top()] ;
        stk.pop();
    }
}
else 
{
    cout << "NO" << endl;
}

    
}

int main(){
    fast;
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    } 
    return 0;
}
