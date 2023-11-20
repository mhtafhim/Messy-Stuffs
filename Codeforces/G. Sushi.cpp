#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

vector<int> graph[10000000];
bool vis[10000000];




void solve(int cs){

    ll n;
    cin >> n ; 

    ll a , b;
    cin >> a >> b;

    ll ans = a * (n-(a+b)+2);

    cout << ans << endl;

    

}

int main(){
    fast;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
