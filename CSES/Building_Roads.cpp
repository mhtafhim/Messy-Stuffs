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

void dfs(int v)
{
    //   cout << v << endl;
    visited[v] = true;

    for (auto u : graph[v])
    {
        //  cout << visited[u] << endl;
        if (!visited[u])
        {
            //   cout << u <<endl;
            dfs(u);
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
    /*
        for(int i = 1 ; i < v ;  i++)
        {
            cout << i << " - " ;
            for(auto u : graph[i])
            {
                cout << u << " ";
            }
            cout << endl;
        }

    */
    int cnt = 0;
    queue<int> stk;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            //      cout << i << endl;
            cnt++;
            stk.push(i);
            dfs(i);
        }
    }

    cout << cnt - 1 << endl;

    int prev = stk.front();
    stk.pop();

    while (!stk.empty())
    {
        cout << prev << " " << stk.front()<< endl;
        prev = stk.front();
        stk.pop();
    }
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
