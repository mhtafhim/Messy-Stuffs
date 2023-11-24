#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    ll n;
    cin >> n ;

    for(int i = 1 ; i <11 ; i++)
    {
        if(i%3!=0)
        for(int j = i+1 ; j < 11 ; j ++)
        {
            if(j %3!=0)
            if((n-i-j)%3!=0 &&  (n-i-j) != i && (n-i-j) != j  && (n-i-j) > 0 )
            {
                cout << "Yes" << endl;
                cout << i << " " <<j << " " << (n-i-j) << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
    


    
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
