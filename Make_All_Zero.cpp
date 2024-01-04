#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    ll n;
    cin >> n;

    vector<ll> v(n);
    ll min = 1e18;
    ll inx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(min > v[i])
        {
            min = v[i];
            inx = i;
        }

    }
        

    map<ll, vector<ll>> mp;

    ll last = n-1;
    cnt 

    for(int i = inx ; i >= 0 ; i --)
    {
        
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



5 3 3 5 2 4 5 2 1