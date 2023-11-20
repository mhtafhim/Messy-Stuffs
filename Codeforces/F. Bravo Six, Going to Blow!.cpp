#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18




void solve(int cs){

    int n , k ;
    cin >> n >> k;

    vector<int> vec(n);

    for(int i = 0 ; i < n ; i ++)
    {
        cin >> vec[i] ;
    }

    ll l = 0 , r = 1e18;

    ll mid;
   

    while(l<r)
    {
        mid = (l+r)/2;
        ll cnt = 0;

        for(int i = 0 ; i < n ; i ++)
        {
            cnt += mid/vec[i];
       //     cout << "cnt = " << mid/vec[i] << endl;
        }
     //    cout << "cnt = " << cnt <<" " << mid   << " " <<l << " "<< r << endl;
       

        if(cnt >= k)
        {
            r = mid;
        }
        else 
        {
            l = mid + 1;
        }

    }

    cout << r << endl;
 

}

int main(){
    fast;
    int t=1;
 //   cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
