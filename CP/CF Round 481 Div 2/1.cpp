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
        vector<ll> v(n);
        for(ll i =0;i<n;i++)
        {
            cin >> v[i] ;
        }

         for(ll i =1;i<n;i++)
        {
            v[0] = v[0]*v[i];
            v[i] = 1;
        }
        ll ans =0;
         for(ll i =0;i<n;i++)
        {
            ans +=v[i];
        }
        ll final = ans*2022;
        cout << final << endl;

    }


   return 0;
}

