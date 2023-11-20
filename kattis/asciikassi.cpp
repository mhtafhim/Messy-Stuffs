#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    int n;
    cin >> n ;

    n+=2;

    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if(i == n-1 || j == n-1 || i == 0 || j == 0 )
            {
                if((i ==0 && j ==0 ) || (i ==0 && j == n-1 ) || (i == n-1 && j ==0 ) || (i == n-1 && j == n-1 ))
                {
                    cout << '+' ;
                }
                else if(i == 0 || i == n-1)
                {
                    cout << '-';
                }
                else 
                {
                    cout << '|';
                }

            }
            else 
            {
                cout << " " ;
            }
        }
        cout << endl;
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
