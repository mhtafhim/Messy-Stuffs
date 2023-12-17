#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18
const int N = 1e6;


void solve(int cs)
{
    

    int n;
    cin >> n;

    vector<int> graph[n+1];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
            cnt++;
    }

  //  cout << cnt << endl;

    cout << (cnt + 1) / 2 << endl;
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
