#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

//    ll ans = 1;
    vector<ll> dp(1000);
    for(int i = 0 ; i < 10 ; i ++)
    {
        for(int j = 0 ; j < 10 ; j ++)
        {
            for(int k = 0 ; k < 10 ; k ++)
            {
                dp[i+j+k]++;
            }
        }
    }

    int q;
    cin >> q;
  //   cout << "dukse" << endl;

    while(q--)
    {
        string n;
        cin >> n ;
        ll ans = 1;

        
        for(int i = 0 ; i < n.length(); i++)
        {
            ans *= dp[n[i]-'0'];
        //    cout << "dukse" << endl;
        }


        cout << ans << endl;


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
