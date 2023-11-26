#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    int n;
    cin >> n ;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    ll ans = 0 ;

    for(int i = 0 ; i < n -2 ; i ++)
    {
        for(int j = i + 1 ;  j < n-1 ; j ++)
        {
            int a =   (n - (j + 1) );
            int b = __gcd(v[i],v[j]);
            ans += a * b;
        //    cout<<v[i] << " "<<v[j]<< " gcd " << (n - (j + 1) )  <<" = " << a << "* " <<  b  << " = " << ans << endl;
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
