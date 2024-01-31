#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll a,b , xa , ya , xb,yb;

    cin >> a >> b >> xa>> ya >> xb>> yb;

    if(xb -xa >= 0)
    {
        if((xb-xa)&1)
        {
           if(ya > yb)
           {
                ll Aparbe = ya-1;
                ll Bparbe = 
           }
           else
           {

           }
        }
        else
        {
           
        }

    }
    else
    {
        cout << "Draw" << endl;
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
