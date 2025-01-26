#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i =0; i < n;i ++){
        cin >> v[i];
    }

    bool ok = true;

    for(int i =0; i < n ; i ++){
        //cout << (n-i-1)*2 << " " << (2*(n-1)- ((n-i-1)*2)) << endl;
        if((v[i] <= (n-i-1)*2)  or (v[i]<=(2*(n-1)- ((n-i-1)*2))))
        {
            ok = false;
            break;
        }
    }

    if(ok)cout << "YES" << endl;
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
