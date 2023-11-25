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

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    vector<int> aa(n), b(n), ans(n);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        aa[i] = tmp;
        a.push_back({tmp, i});
        // cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    int cnt = 0;
    int inx = n - 1;
    int j = 0;
    for (int i = 0,k = x-1; i < x; i++,k--)
    {
        auto tmp = a[i];
        ans[tmp.second] = b[k];
        j++;
    }

    for (int i = j; i < n; i++)
    {
        auto tmp = a[i];
        ans[tmp.second] = b[inx];
        inx--;
    }

    int cntt = 0;

    for (int i = 0; i < n; i++)
    {
        if (aa[i] > ans[i])
            cntt++;
    }

    //    cout << cntt << " " << x << endl;

    if (cntt == x)
    {
        cout << "Yes" << endl;
        for (auto p : ans)
        {
            cout << p << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
        //   return;
    }
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
