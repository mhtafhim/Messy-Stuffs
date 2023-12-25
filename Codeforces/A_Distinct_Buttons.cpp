#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n;
    cin >> n;

    vector<int> v(4);

    for(int i = 0 ;i < n ; i ++)
    {
        int a,b;
        cin >> a >> b;

        if(a > 0)v[0] = 1;
        else if(a < 0)v[1] = 1;

        if(b > 0) v[2] = 1;
        else if(b < 0) v[3] = 1;
    }

    int cnt = 0;
    for(int i = 0 ; i < 4 ; i ++)
    {
        if(v[i]==1) cnt ++;
    }

    if(cnt <= 3) cout << "YES" << endl;
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
