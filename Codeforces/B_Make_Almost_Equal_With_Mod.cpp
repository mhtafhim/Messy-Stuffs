#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18



void solve(int cs)
{
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    set<ll> st;
    ll cnt = 0;
    ll ans = -1;

    for (ll j = 1 ; j <=1e18 ; j*=2)
    {
        cnt = 0;
        st.clear();
        ans = j;
   //            cout << "k = " << j << endl;

        for (ll i = 0; i < n; i++)
        {
            //      cout << v[i] % j << " ";
            st.insert(v[i] % j);
        }
    //    cout << st.size() << endl;
        //   cout << endl;

        if (st.size() == 2)
        {
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    fast;
    
    int t = 1;
    cin >> t;
  
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
