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

    pair<int, int> v[4];

    vector<int> vv;

    for (int i = 0; i < 4; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (j != i and v[i].first == v[j].first)
                vv.push_back(abs(v[i].second - v[j].second));
        }
    }

    cout << vv[0] * vv[1] << endl;
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
