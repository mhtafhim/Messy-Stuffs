#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n;
    cin >> n ;
    vector<ll > even , odd,ans1 , ans2;

    for(int i = 0 ; i< n ; i ++)
    {
        ll tmp;
        cin >> tmp;
        if(tmp&1) odd.push_back(tmp);
        else even.push_back(tmp);
    }


      ll sz1 = even.size();
    ll sz2 = odd.size();
    
 //   cout << sz1 << " " << sz2 << endl;

    if((sz1&1) || sz2&1) 
    {
        cout << -1 << endl;
        return;
    }

    sort(even.rbegin(),even.rend());
    sort(odd.rbegin(),odd.rend());

  

    for(int i = 0 ; i< sz1/2; i ++)
    {
       // cout << even[i] << 
        ans1.push_back((even[i]+even[i+sz1/2])/2);
        ans2.push_back(abs(even[i]-even[i+sz1/2])/2);
    }

    for(int i = 0 ; i< sz2/2; i ++)
    {
        ans1.push_back((odd[i]+odd[i+sz2/2])/2);
        ans2.push_back(abs(odd[i]-odd[i+sz2/2])/2);
        
    }






    for(auto a : ans1)cout << a << " ";
    for(auto b : ans2) cout << b << " ";

    cout << endl;
    
    
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
