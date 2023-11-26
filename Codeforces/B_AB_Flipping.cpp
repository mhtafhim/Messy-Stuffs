#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n ;
    cin >> n ;
    string ss;
    cin >> ss;

    ll ans = 0 ,cntB = 0;
    ll prev = 0;

    for(int i = n-1 ; i >= 0 ; i -- )
    {
        if(ss[i] == 'B')cntB++;
        else if(cntB > 0)
        {
            ans+= cntB ;
            cntB=1;
        } 
    }

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
