#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0 ; i < n  ; i ++) cin >> v[i];


    bool ok = true;
    ll mn = v[n-1];

    for(int i = n-2 ; i >=0 ; i--)
    {
     //   cout << mn << endl;
        if(mn < v[i])
        {
            
            if(v[i]>9)
            {
                ll d1 , d2;
                
                d1 = v[i]%10;
                d2 = v[i]/10;
            //    cout << d1 << " " << d2 << endl;
                if(d1 > mn or d1 < d2)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    mn = d2;
                }
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            mn = v[i];
        }
    }

    cout << "YES" << endl;
    
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
