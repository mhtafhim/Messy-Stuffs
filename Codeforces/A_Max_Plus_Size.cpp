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

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int idx = 0;
    int max = -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            idx = i;
            max = v[i];
        }
        else if (v[i] == max && i % 2 == 0)
        {
            idx = i;
        }
    }

    int ans = max;
    if (v.size() % 2 == 0)
    {
        ans += v.size() / 2;
    }
    else
    {
        if (idx % 2 == 0)
            ans += (v.size() / 2 + 1);
        else 
           ans += v.size() / 2;
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
