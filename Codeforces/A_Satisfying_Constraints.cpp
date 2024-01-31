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

    ll mn = 0, mx = 1e9;
    vector<ll> st;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        if (a == 1)
            mn = max(mn, b);
        else if (a == 2)
            mx = min(mx, b);
        else
            st.push_back(b);
    }

    sort(st.begin(), st.end());

    ll cnt = upper_bound(st.begin(), st.end(), mx) - lower_bound(st.begin(), st.end(), mn);

    ll tmp = mx - mn ;
  //  cout << tmp << endl;
    cout << max((ll)0,mx - mn + 1 - cnt) << endl;
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
