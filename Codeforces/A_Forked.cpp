#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int dx[]={1,1,-1,-1};int dy[]={1,-1,1,-1};//Knight Direction


void solve(int cs){
    ll a,b,xk,yk,xq,yq;

    cin >> a >> b;
    cin >> xk >> yk >> xq >> yq;

    bool ok = false;

    set<pair<int,int>> st;
    ll cnt = 0;

    for(int i = 0 ; i < 4 ; i ++)
    {
        st.insert({xk+dx[i]*a , yk + dy[i]*b});
        st.insert({xk+dx[i]*b , yk + dy[i]*a});
    }
   // for(auto [first,second] : st)cout << first <<" " << second << endl;
   // cout << endl;

     for(int i = 0 ; i < 4 ; i ++)
    {
        if(st.count({xq+dx[i]*a , yq + dy[i]*b}))
        {
            st.erase({xq+dx[i]*a , yq + dy[i]*b});
           // cout << xq+dx[i]*a << " " << yq + dy[i]*b << endl;
            cnt++;
        }
        if(st.count({xq+dx[i]*b , yq + dy[i]*a}))
        {
            st.erase({xq+dx[i]*b , yq + dy[i]*a});
        //     cout << xq+dx[i]*b << " " << yq + dy[i]*a << endl;
             cnt++;
        }
    }

    cout << cnt << endl;
   
//bla bla
  
    
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
