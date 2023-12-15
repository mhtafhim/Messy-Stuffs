#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n,glass , mug;
    cin >> n >> glass >> mug;

    int rem1 =0, rem2=0;

    for(int i = 0 ; i < n  ; i ++)
    {
        
        if(rem1 == glass)rem1 = 0;
        else if(rem2 == 0) rem2 = mug;
        else 
        {
            int tmp = (glass - rem1);
            if(rem2 >= tmp)
            {
                rem2 -= tmp;
                rem1 += tmp;
            }
            else
            {
                rem1 += rem2 ;
                rem2 = 0;
                //rem1 += tmp;
            }

        }

      //  cout << rem1 << " " << rem2 << endl;
    }

    cout << rem1 << " " << rem2 << endl;
    
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
