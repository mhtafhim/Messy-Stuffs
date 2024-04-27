#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

ll remainder(ll x)
{
    return (x % mod + mod)%mod;
}

ll maxSubArraySum(vector<ll> a, ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve(int cs)
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll mx = maxSubArraySum(v, v.size());

    if (mx > 0)
    {
        for (int i = 0; i < k; i++)
        {
            sum += (mx);
            sum%=mod;
            mx += mx;
            mx%=mod;
        }
    }

    cout << ((sum%mod)+mod)%mod << endl;
   // cout << (sum+mod)%mod << endl;
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
