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

    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector<ll> ans(n);
    ll sum = 0, cnt = 0;
    queue<ll> q;

    for (int i = 0; i < n; i++)
    {

     //   cout << v[i].first << " " << sum << endl;

        if (sum < v[i].first)
        {
            while (!q.empty())
            {
                int inx = q.front();
                ans[inx] = cnt - 1;
                q.pop();
            }
        }
        sum += v[i].first;
        q.push(v[i].second);
        cnt++;
    }

    while (!q.empty())
    {
        int inx = q.front();
        ans[inx] = cnt - 1;
        q.pop();
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
