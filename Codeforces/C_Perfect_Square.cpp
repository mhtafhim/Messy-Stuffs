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
    char ss[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ss[i][j];
        }
    }

    ll cnt = 0;
    int lim = n / 2;

    for (int k = 1; k <= lim; k++)
    {
        // vector<int> alpha(26);
        bool z = false;
        int mx = -1;
        int x = -1;
        for (int i = k - 1; i < n - k; i++)
        {
            mx = -1;
            //     cout << ss[k - 1][i] << ss[n - i - 1][k - 1] << ss[n - k][i] << ss[i][n - i] << endl;
            mx = max(mx, (int)ss[k - 1][i]);
            mx = max(mx, (int)ss[i][n - k]);
            mx = max(mx, (int)ss[n - k][n - i - 1]);
            mx = max(mx, (int)ss[n - i - 1][k - 1]);

            cnt += mx - (int)ss[k - 1][i];
            cnt += mx - (int)ss[i][n - k];
            cnt += mx - (int)ss[n - k][n - i - 1];
            cnt += mx - (int)ss[n - i - 1][k - 1];
        //    cout << ss[k - 1][i] << ss[i][n - k] << ss[n - k][n - i - 1] << ss[n - i - 1][k - 1] << endl;
       //     cout << (char)mx << " = ";
        //    cout << cnt << endl;
        }

        // for (int i = k - 1; i < n - k; i++)
        // {
        //     // cout << ss[k-1][i] << ss[i][k-1] << ss[n-k][i]<< ss[i][n-k];
        //     cnt += mx - (int)ss[k - 1][i];
        //     cnt += mx - (int)ss[i][k - 1];
        //     cnt += mx - (int)ss[n - k][i];
        //     cnt += mx - (int)ss[i][n - k];
        // }
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
