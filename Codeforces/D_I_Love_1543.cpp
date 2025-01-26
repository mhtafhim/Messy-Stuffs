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
    int n, m;
    cin >> n >> m;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << v[i][j];
    //     }
    //     cout << endl;
    // }

    int limit = (min(n, m) / 2);

    int cnt = 0;

    for (int i = 0; i < limit; i++)
    {

        string t;
        for (int a = i; a < m - i; a++)
        {

            // cout << v[i][a];
            // cout << "what  " << a << "   | " << endl;
            t += v[i][a];
        }
        for (int b = i + 1; b < n - i; b++)
        {
            // cout << v[b][m - i - 1];
            // cout << "what  " << b << "   | " << endl;
            t += v[b][m - i - 1];
        }
        for (int c = m - i - 2; c >= i; c--)
        {
            // cout << v[n - i-1][c];
            // cout << "what  " << c << "   | " << endl;
            t += v[n - i - 1][c];
        }
        for (int d = n - i - 2; d > i; d--)
        {
            // cout << v[d][i];
            // cout << "what  " << d << "   | " << endl;
            t += v[d][i];
        }

        t += t[0];
        t += t[1];
        t += t[2];

        for (int it = 0; it < t.size() - 3; it++)
        {
            cnt += (t.substr(it, 4) == "1543");
        }

        //cout << t << endl;
    }

    cout << cnt << endl;
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
