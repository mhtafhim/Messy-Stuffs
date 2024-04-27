#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n ;
    cin >> n;
    
    vector<ll> v(n);

    for(int i = 0 ; i < n ; i ++)cin >> v[i];

    sort(v.begin(),v.end());

    ll mid = (n+1)/2;
  //  cout << mid << endl;

    ll uper = upper_bound(v.begin(),v.end(),v[mid-1]) - v.begin();

  //  for(auto x : v) cout << x << " ";
    //cout << endl;

    cout << uper - mid + 1<< endl;
    
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
