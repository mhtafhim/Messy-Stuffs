#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction D L U R
int dp[1000][1000];
char grid[1000][1000];
bool visited[1000][1000];
char mp[1000][1000];

int H,W,cnt,l,r;


bool ok = false;



void dfs(int x,int y)
{
  //  dp[x][y]= distance+1;
  //  it++;
  //  cout << grid[x][y]  << " : " << dp[x][y]<< endl;
// cout << x <<" " <<y<< endl ;
    visited[x][y] = true;
    for(int i = 0; i<4; i++)
    {
        if(grid[x+ dx[i]][y+ dy[i]] == 'A') return;
        if(!visited[x+ dx[i]][y+ dy[i]] && grid[x+ dx[i]][y+ dy[i]] != '0' && (x + dx[i]) < (H) && (x+ dx[i]) >=0 &&(y + dy[i]) < (W) && (y + dy[i]) >= 0  )
        {
            dfs(x+ dx[i],y+ dy[i]);
        }
        cout << mp[x][y];

    }
}

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

    mp[a][b] = 'A';
  
    
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

                l = x+ dx[i] , r = y+ dy[i];

                 if(i == 0)mp[x+ dx[i]][y+ dy[i]]= 'D';
                else if(i == 1 ) mp[x+ dx[i]][y+ dy[i]]= 'R';
                else if(i == 2 ) mp[x+ dx[i]][y+ dy[i]]= 'U';
                else if(i == 3 ) mp[x+ dx[i]][y+ dy[i]]= 'L';

              //  cout <<  << endl;
                cnt = dp[x][y]+1;
              //  cout << '(' << x+ dx[i] << ',' << y+ dy[i] << ')' ;
             

                ok = true;
                return;
            }
            else if (!visited[x+ dx[i]][y+ dy[i]] && '.' == grid[x+ dx[i]][y+ dy[i]]  && (x + dx[i]) < (H) && (x+ dx[i]) >=0 &&(y + dy[i]) < (W) && (y + dy[i]) >= 0 ) {
  
                // Push the adjacent node to the queue
                q.push({x+ dx[i],y+ dy[i]});
                dp[x+ dx[i]][y+ dy[i]] = dp[x][y] + 1;
                //D L U R

                if(i == 0)mp[x+ dx[i]][y+ dy[i]]= 'D';
                else if(i == 1 ) mp[x+ dx[i]][y+ dy[i]]= 'R';
                else if(i == 2 ) mp[x+ dx[i]][y+ dy[i]]= 'U';
                else if(i == 3 ) mp[x+ dx[i]][y+ dy[i]]= 'L';
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
            mp[i][j] = '0';
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

for(int i =0 ; i< H ; i ++)
    {
        for(int j = 0 ; j< W ; j++)
        {
           
            cout << mp[i][j];
        }
        cout << endl;
    }
    


if(ok){
    cout << "YES" << endl;
    cout << cnt << endl;
    
    dfs(l,r);
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
