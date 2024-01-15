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

    ll n, f, a, b;

    cin >> n >> f >> a >> b;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll sum = min(v[0] * a, b);

    for (int i = 1; i < n; i++)
    {
        sum += min((v[i] - v[i - 1]) * a, b);
    }

    cout << (sum < f ? "YES" : "NO") << endl;
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
