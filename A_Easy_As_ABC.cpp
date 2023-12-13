#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // 8 direction
vector<string> s(3);
set<string> st;

void dfs(int x, int y, int cnt, string tmp, int vis[3][3])
{
    tmp += s[x][y];
    if (cnt == 3)
    {
        st.insert(tmp);
        return;
    }
    vis[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        if ((x + dx[i]) < 3 && (x + dx[i]) >= 0 && (y + dy[i]) < 3 && (y + dy[i]) >= 0 && !vis[(x + dx[i])][(y + dy[i])])
        {
            dfs((x + dx[i]), (y + dy[i]), cnt + 1, tmp, vis);
        }
    }
}

void solve(int cs)
{
    int vis[3][3];

    for (int i = 0; i < 3; i++)
        cin >> s[i];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
                for (int m = 0; m < 3; m++)
                    vis[k][m] = false;

            dfs(i, j, 1, "", vis);
        }

    cout << *st.begin() << endl;
    // cout << s[0][0];
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
