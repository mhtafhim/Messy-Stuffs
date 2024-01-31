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
    ll n, m, kk;

    cin >> n >> m >> kk;

    string s;
    cin >> s;
    vector<int> alpha(27, 0);
    bool ok = true;
    char curr = 'a';
    set<char> st, last;
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < kk; j++)
        {
            if ('a' + i == s[j])
            {
                alpha[i] = j;
                break;
            }
        }
    }

    // for (int i = 0; i < m; i++)
    //     cout << alpha[i] << " ";
    // cout << endl;

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            ll cnt = 1;
            for (int k = alpha[i] + 1; k < kk; k++)
            {
                if (s[k] == (char)('a' + j))
                {
                 //   cout << s[i] << " " << (char)('a' + j) << endl;
                    cnt++;
                }
            }
            // cout << i << " " << j << ' ';
            // cout << cnt << endl;
            if (cnt < m)
            {
                cout << "NO" << endl;
                cout << (char)('a' + i);
                for (int l = 0; l < n - 1; l++)
                    cout << (char)('a' + j);
                cout << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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
