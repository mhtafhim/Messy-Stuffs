#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n;
    cin >> n;

    string ss;
    cin >> ss;

    ll ans = (n*(n+1))/2;

    set<int> st;

    for(int i = 0 ; i < n ; i ++)
    {
        if(!st.count(ss[i]))
        {
            for(int j =  i + 1  ; j < n ; j ++)
            {
                if(ss[j]== ss[i])
                {
                    ans -= (n-j);
                    st.insert(ss[i]);
                }
            }
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
