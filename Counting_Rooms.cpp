#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int dp[1000][1000];
char grid[1000][1000];
bool visited[1000][1000];
int H,W;

void dfs(int x,int y)
{
  //  dp[x][y]= distance+1;
  //  it++;
  //  cout << grid[x][y]  << " : " << dp[x][y]<< endl;
// cout << x <<" " <<y<< endl ;
    visited[x][y] = true;
    for(int i = 0; i<4; i++)
    {
        if(!visited[x+ dx[i]][y+ dy[i]] &&grid[x][y] == grid[x+ dx[i]][y+ dy[i]]  && (x + dx[i]) < (H) && (x+ dx[i]) >=0 &&(y + dy[i]) < (W) && (y + dy[i]) >= 0  )
        {
            dfs(x+ dx[i],y+ dy[i]);
        }

    }
}



void solve(int cs){
  //  int n,m;
    cin >> H >> W;
   // char graph[n][m];

    for(int i =0 ; i< H ; i ++)
    {
        for(int j = 0 ; j< W ; j++)
        {
            cin >> grid[i][j];
        }
    }

    int cnt = 0 ; 

     for(int i =0 ; i< H ; i ++)
    {
        for(int j = 0 ; j< W ; j++)
        {
            if(!visited[i][j] && grid[i][j] == '.'){
                cnt++;
                dfs(i,j);
            }
        }
    }

    cout << cnt << endl;

    
    
    
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
