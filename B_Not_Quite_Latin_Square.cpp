#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){

    char arr[3][3];

    int A =0 , B = 0 , C = 0;

    for(int i = 0 ; i < 3 ; i ++)
    {
        for(int j = 0 ; j < 3 ; j ++)
        {
            char tmp;
            cin >> tmp;

            if(tmp == 'A')A++;
            else if(tmp == 'B')B++;
            else C++;

        }
    }

    if(A<3)cout << 'A' << endl;
    else if(B<3)cout << 'B' << endl;
    else cout << 'C' << endl;
    
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
