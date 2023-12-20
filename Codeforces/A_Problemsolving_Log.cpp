#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n;
    cin >> n;

    vector<int> v(26);

    string ss;
    cin >> ss;

    for(int i =0 ; i < n ; i ++)
    {
        v[ss[i]-'A']++;
    }

    int cnt =0;

    for(int i = 0 ;  i < 26 ; i++)
    {
        if(v[i] >= i+1)cnt ++;
    }

    cout << cnt <<endl;
    
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
