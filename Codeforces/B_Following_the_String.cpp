#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n ;
    cin >> n ;

    vector<ll> v(n);
    vector<ll> vv[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> v[i];
     //   cout << v[i] << " ";
    }
  //  cout << endl;

    for(int i = 0 ; i < n ; i++)
    {
        vv[v[i]].push_back(i);
    }

    vector<char> ss(n);

    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < vv[i].size();j++)
        {
       //     cout << vv[i][j] << " ";
            ss[vv[i][j]] = 'a' + j;
        }
    //    cout << endl;
    }

    for(auto x : ss)cout << x;
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
