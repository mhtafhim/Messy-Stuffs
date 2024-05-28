#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

typedef vector<ll> vl;


void solve(int cs){

    ll n;
    cin >> n;

    vl v(n);

    for(int i = 0 ; i < n ; i ++)cin >> v[i];


    ll mn = v[0];
    bool ok = true;
    int i = 1;

    for( ; i < n ; i ++)
    {
        if(v[i] < v[i-1])
        {
            break;
        }
        mn = min(mn,v[i]);
    }
    i++;
    for(; i < n ; i ++)
    {
        if(v[i] > mn || v[i] < v[i-1])ok = false;
    }

    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;

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
