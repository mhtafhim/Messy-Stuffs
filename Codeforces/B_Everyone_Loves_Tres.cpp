#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n;
    cin >> n;

    if(n == 1 || n == 3)
    {
        cout << -1 << endl;
    }
    else if(n%2==0)
    {
        for(int i =0;i < n-2 ; i ++)cout << '3';
        cout <<"66" <<endl;
    }
    else
    {
        for(int i = 0 ; i < n-4 ; i++)
        {
            cout << '3';
        }
        cout << "6366" << endl;
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
