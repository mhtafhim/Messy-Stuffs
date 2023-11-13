#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

vector<int> graph[1000000];
bool visited[1000000] = {false};
int parent[1000000];
int dp[1000000] ;

void bfs(int v, int n)
{

    queue<int> qu;

    qu.push(v);
    visited[v] = true;
    parent[v] = -1;
    dp[v] = 1;
    //    cout << v << " ";

    while (!qu.empty())
    {

        int u = qu.front();
        //  cout << u << " ";

        qu.pop();
        for (auto x : graph[u])
        {
            if (!visited[x])
            {
                qu.push(x);
                parent[x] = u;
                dp[x] = dp[u] + 1;
                visited[x] = true;
            }
        }
    }
}

void solve(int cs)
{

    int v, e;
    cin >> v >> e;

    //   vector<int> graph[v+1];

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1, v);

    //  cout << endl;

    if (dp[v] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << dp[v] << endl;

    stack<int> stk;

    stk.push(v);
    int prev = parent[v];
    //  cout << prev << " ";

    while (1)
    {
        if (prev == -1)
            break;
        stk.push(prev);
        prev = parent[prev];
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return ;
}

int main()
{
    fast;
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
