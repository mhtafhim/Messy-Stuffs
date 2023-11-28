#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18




void solve(int cs){

    

    string x = "বাইরে চলে গিয়েছে" ; 

    for(int i = 0 ; i < 50 ; i ++)
    {
        cout << (wchar_t)x[0] << endl;
    }
    cout << x << endl;
    cout << "//বাইরে চলে গিয়েছে" << endl;
    
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
