#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(int cs)
{

    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end(), greater<pair<ll, ll>>());

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        auto pivot = v[i];
        ll l = 0;
        ll r = n - 1;
        ll mid = (l + r) / 2;
        ll last = 0;

        while (l <= r)
        {
            bool flag = true;

            mid = (l + r) / 2;

            if (pivot.second > 9)
                flag = false;
            else if (binpow(v[mid].first, pivot.second) > pivot.first)
                flag = false;

            if (flag)
            {
                r = mid - 1;
                last = mid;
            }

            else
                l = mid + 1;
        }
        cout << i << " " << pivot.first << " " << pivot.second << " " << last << " ";
        cout << v[last].first << endl;

        ans += (n - mid);
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
