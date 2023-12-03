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
    bool ok = true;
    vector<ll> v(n), diff;
    unordered_set<ll> st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert(v[i]);
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    ll mx = *max_element(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        diff.push_back(abs(mx - v[i]));

    ll gen_gcd = diff[0];

    for (int i = 1; i < diff.size(); i++)
        gen_gcd = __gcd(gen_gcd, diff[i]);

    ll ans = 0;

    for (auto u : diff)
    {
        ans += u / gen_gcd;
    }

    ll tt = mx;
    while (true)
    {
        tt = tt - gen_gcd;
        ans += 1;
        if (!st.count(tt))
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
