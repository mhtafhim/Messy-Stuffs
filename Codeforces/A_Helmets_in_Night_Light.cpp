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
    ll n, p;
    cin >> n >> p;

    vector<pair<int, int>> v(n);
    queue<pair<int, int>> pr;

    for (int i = 0; i < n; i++)
        cin >> v[i].second;

    for (int i = 0; i < n; i++)
        cin >> v[i].first;

    sort(v.begin(), v.end());
    ll cost = 0;

    int track = 0;

    cost += p;
    track++;
    if (v[0].first <= p)
        pr.push(v[0]);

    while (track < n)
    {
        if (!pr.empty())
        {
            auto [a, b] = pr.front();
            pr.pop();
          //  cout << a << " " << b << endl;
            for (int i = 0; i < b; i++)
            {
                cost += a;
               
                if (v[track].first <= p)
                    pr.push(v[track]);

                 track++;
                if (track == n)
                    break;
            }
        }
        else
        {
            cost += p;
            track++;
        }
    }

    cout << cost << endl;
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
