#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n;
    cin >> n ;
    vector<ll> v(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    vector<ll> suff(n);

    suff[0] = v[n-1];

    for(int i = 1,j = n-2 ; i < n ; i ++ , j --)
    {
        suff[i] = suff[i-1] + v[j]; 
    }

    ll ans = suff[n-1];

    for(int i = 0 ; i < n-1 ; i++)if(suff[i]>0)ans+= suff[i];

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
