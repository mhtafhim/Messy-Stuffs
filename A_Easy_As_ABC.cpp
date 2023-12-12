#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
vector<string> s(3);
bool vis[3][3];
int cost[3][3];
char parent[3][3];


void bfs(int i ,int j)
{

    vis[i][j] = true;
    queue<pair<int,int>> pr;

    pr.push({i,j});

    while(!pr.empty())
    {
        auto [first,second] = pr.front();
        pr.pop();

        for(int i = 0 ; i < 8 ; i ++)
        {
            if()
        }

    }
    

}


void solve(int cs){

    for(int i = 0 ; i < 3 ; i ++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            vis[i][j] = false;
            cost[i][j] = 1e9;
            parent[i][j] = '0';
        }
    }
    

    for(int i = 0 ; i < 3 ; i ++)cin >> s[i];

   // cout << s[0][0];



    
    
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
