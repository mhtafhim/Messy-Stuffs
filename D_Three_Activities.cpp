#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int FindMaxS(int X, int Y, int Z, int n, vector<int> &A,
             vector<int> &B, vector<int> &C)
{

    vector<vector<vector<vector<int>>>> dp(
        X + 1,
        vector<vector<vector<int>>>(
            Y + 1, vector<vector<int>>(
                       Z + 1, vector<int>(n + 1, 0))));

    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            for (int z = 0; z <= Z; z++)
            {
                for (int i = 1; i <= n; i++)
                {
                    int ch = INT_MIN, ca = INT_MIN,
                        co = INT_MIN, no = INT_MIN;
                    if (x > 0)
                        ch = A[i - 1] + dp[x - 1][y][z][i - 1];
                    if (y > 0)
                        ca = B[i - 1] + dp[x][y - 1][z][i - 1];
                    if (z > 0)
                        co = C[i - 1] + dp[x][y][z - 1][i - 1];
                    no = dp[x][y][z][i - 1];
                    dp[x][y][z][i] = max(ch, max(ca, max(co, no)));
                }
            }
        }
    }
    return dp[X][Y][Z][n];
}

void solve(int cs)
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;

    cout << FindMaxS(1, 1, 1, n, a, b, c) << endl;
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
