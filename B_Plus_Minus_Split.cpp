#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n;
    cin >> n;

    vector<char> v(n);

    ll minus = 0 ,plus =0;

    for(int i = 0 ; i < n ; i ++)
    {
        char tmp;
        cin >> tmp;
        if(tmp =='+')plus++;
        else minus++;

    }

    cout << abs(plus-minus) << endl;
    
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
