#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define memset(v,x) memset((v),x,(sizeof(v)))
using namespace std;
typedef long long int ll;


int main()
{
    fast

    ll t;
    t=1;
    cin >> t;
    for(int tc =1;tc<=t;tc++)
    {

        ll n;
        cin >> n;

        ll ans = (sqrt(1+8*n))+1;
        ll ans2 = (ans/2);

        ll ans3 = ans2*(ans2-1)/2;

        cout << ans2+(n-ans3) << endl;
    }


   return 0;
}
