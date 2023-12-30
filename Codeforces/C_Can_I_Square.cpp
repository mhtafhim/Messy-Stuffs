#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    ll n;
    cin >> n;

    ll sum = 0;

    for(int i = 0 ; i < n ; i ++)
    {
        ll tmp;
        cin >> tmp;
        sum+= tmp;
    }

    ll tmp2 = sqrt(sum);

    if(tmp2*tmp2 == sum)cout << "YES" << endl;
    else cout << "NO" << endl;
    
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
