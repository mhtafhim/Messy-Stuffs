#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long ll;

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
        ll ans=0,num =1;
        ll dx=1,cnt = 2;
        while(dx<=n)
        {
            ans+=num;
            num +=dx;
            cnt++;
            if(cnt>=2)
            {
                dx++;
                cnt=0;
            }

        }

        ll c = 1000000007;
        ll fin = ( ( 2022 % c ) * ( ans % c ) ) % c;
        cout << fin << endl;


    }


   return 0;
}
