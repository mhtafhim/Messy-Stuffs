#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll x , y , z;
    cin >> x >> y >> z;

int even =0,odd = 0;
    if(x&1) odd++;
    if(y&1) odd++;
    if(z&1) odd++;

    even = 3 - odd;

    bool a = x&1;
    bool b = y&1;
    bool c = z&1;
    

  //  cout << even << " " << odd << endl;

    if(even ==0 or odd == 0)
    {
        cout << 1 << ' ' << 1 << ' ' << 1 << endl;
    }
    else if(even > odd)
    {
        cout << a << ' ' << b << ' ' << c<< endl;
    }
    else 
    {
         cout << !a << ' ' << !b << ' ' << !c<< endl;
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
