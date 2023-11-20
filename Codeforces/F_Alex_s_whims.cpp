#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n,q;
    cin >> n >> q;


    for(int i =1; i < n ; i++)
    {
        cout << i << " " << i + 1 << endl;
    }

    ll cur_len = n-1;
  //  ll con = 4;
    while(q--)
    {
        int qq;
        cin >> qq;

        if(qq == cur_len)
        {
            cout << "-1 -1 -1" << endl;
            continue;
        }

        cout << n << " " << cur_len << " " << qq << endl;

        cur_len = qq;
    }


    
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
