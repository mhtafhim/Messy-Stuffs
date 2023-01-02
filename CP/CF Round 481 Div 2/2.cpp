#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
const long long MOD = 1000000007;
typedef long long int ll;

int main()
{

    fast
    int t;
    t=1;
   cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll n1,n2,n3;
        ll x = n;
        ll y = n+1;
        ll z = (2*n+1);
        if(x%3==0)x/=3;
        else if(y%3==0)y/=3;
        else z/=3;
    //    cout  << n%MOD << " " << ((n+1)%MOD) << " " << ((2*n+1)%MOD) << endl;
        n1 = (( (x*y)%MOD * z ));
        n2 = (((n*(n+1))/2));
        ll fin = (( n1 - n2 )%MOD+MOD)%MOD;

        ll ans = ((ll)2022 * fin%MOD)%MOD;

      //  cout  << n1 <<    " " << n2 << endl ;
        cout << ans << endl;


    }


   return 0;
}
