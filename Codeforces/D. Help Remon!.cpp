#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

vector<int> graph[10000000];
bool vis[10000000];

void dfs(int v)
{
    vis[v] = true;
    cout << v - 1000000 << " ";

    for(auto u : graph[v])
    {
        if(!vis[u])
            dfs(u);
    }
}


void solve(int cs){

      int n;

    cin >> n ;

    unordered_set<int> st;

    int mn = INT_MAX;

    //   set<int> set1,set2;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a+=1000000, b+=1000000;
        if(st.count(a))
            st.erase(a);
        else
            st.insert(a);
      
        if(st.count(b))
            st.erase(b);
        else
            st.insert(b);

        

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(*st.begin());

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
