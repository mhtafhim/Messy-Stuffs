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

    vector<ll> x(n), y(n);

    for (auto &z : x)
        cin >> z;
    for (auto &z : y)
        cin >> z;

    vector<pair<pair<ll, ll>, ll>> a, b;

    for (int i = 0; i < n; i++)
    {
        a.push_back({{x[i], y[i]}, i});
        b.push_back({{y[i], x[i]}, i});
    }

    sort(a.begin(), a.end(), greater<pair<pair<ll, ll>, ll>>());
    sort(b.begin(), b.end(), greater<pair<pair<ll, ll>, ll>>());

    // for (pair<pair<ll, ll>, ll> aa : a)
    //     cout << aa.first.first << " " << aa.first.second << " " << aa.second << endl;
    // for (pair<pair<ll, ll>, ll> aa : b)
    //     cout << aa.first.first << " " << aa.first.second << " " << aa.second << endl;
    vector<bool> vis(n);

    ll cnt = 0;

    ll ans = 0;
    ll i = 0, j = 0;

    while (cnt < n)
    {
        //  cout << cnt << " ";
        while (cnt < n)
        {
            if (!vis[a[i].second])
            {
                if (a[i].first.first > b[j].first.first)
                {

                    ans += a[i].first.first - 1;
                    cnt++;
                    vis[a[i].second] = true;
                    i++;
                    break;
                }
                else
                {
                    if (!vis[b[j].second])
                    {
                        ans += b[j].first.second - 1;
                        cnt++;
                        vis[b[j].second] = true;
                        j++;
                        break;
                    }
                }
            }
            else
            {
                i++;
            }
        }

        while (cnt < n)
        {
            if (!vis[b[j].second])
            {
                if (a[i].first.first < b[i].first.first)
                {

                    ans -= b[j].first.first - 1;
                    cnt++;
                    vis[b[j].second] = true;
                    j++;
                    break;
                }

                else
                {
                    {
                        ans -= a[i].first.second - 1;
                        cnt++;
                        vis[a[i].second] = true;
                        i++;
                        break;
                    }
                                }
            }
            else
            {
                j++;
            }
        }

        //    cout << ans << endl;
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
