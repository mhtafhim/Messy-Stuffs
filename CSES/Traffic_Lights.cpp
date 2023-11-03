#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n,q;
    cin >> n>>q ;

    stack<pair<int,int>> qq;

    qq.push({0,n});

    while(q--)
    {
        int x;
        cin >> x ; 

         stack<pair<int,int>> tmpq;

        while(!qq.empty())
        {
            pair<int,int> pr = qq.top();

            if(pr.first>=x  && pr.second<=x)
            {
                
            }
        }

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
