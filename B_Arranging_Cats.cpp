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
    string a, b;
    cin >> a >> b;

    int cnt = 0, match = 0, cnta = 0;

    for (int i = 0; i < n; i++)
    {
        if (b[i] == '1' and a[i] == '1')
            match++;

        if (b[i] == '1')
            cnt++;

        if (a[i] == '1')
            cnta++;
    }

    //    cout << cnt << " " << match << " ";
    // cout << max(0, cnta - cnt) << endl;

    cout << cnt - match + max(0, cnta - cnt) << endl;
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
