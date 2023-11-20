#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    ll x,y,z;
    cin >> x >> y >> z;

    unordered_set<ll> st[2];

    ll mx = min(x,y);

    ll a,b,c;

    for(ll i = 1 ; i <= mx ; i ++ )
    {
        if(x%i==0 && y%i==0)
        {
            st[0].insert(x/i);
            st[1].insert(y/i);
        }
        
    }


    for(auto u : st[0])
    {
        if(z%u==0 && st[1].count(z/u)  && ((z/u)*(x/u))==y)
        {
            a = u;
            b = z/u;
            c = x/u;

        }
    }

    ll ans = (a+b+c) * 4;
    cout << ans << endl;
    
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
