#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    int m,n;
    cin >> m  >> n ;
     vector<int> bis(m),chips(n);

     for(int i = 0 ; i < m ; i ++)
     {
        cin >> bis[i]; 
     }
     for(int i = 0 ; i < n ; i ++)
     {
        cin >> chips[i]; 
     }

    sort(bis.begin(),bis.end());
    sort(chips.begin(),chips.end());

    int l,r;
    cin >> l >> r;
    ll cnt = 0 ;
    for(int i = 0 ; i < bis.size() ; i ++)
    {
        int mn = l - bis[i];
        int mx = r - bis[i];

        int x = lower_bound(chips.begin(),chips.end(),mn) - chips.begin();
        int y = upper_bound(chips.begin(),chips.end(),mx) - chips.begin();
        cnt += y - x ; 
    }

    cout << cnt << endl;

    
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
