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
    vector<int> vec(n + 1);
    vector<int> p, q;

    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        p.push_back(a);
        q.push_back(b);
        vec[a]++;
        vec[b + 1]--;
    }

    vector<int> sum(n + 1), r(n + 1), g(n + 1), b(n + 1);
    r[0] = 0, g[0] = 0, b[0] = 0;

    sum[0] = 0;
    //   cout << sum[1] <<   " ";
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + vec[i];
        r[i] = r[i - 1] + (sum[i] % 3 == 1);
        b[i] = b[i - 1] + (sum[i] % 3 == 2);
        g[i] = g[i - 1] + (sum[i] % 3 == 0);

        //    cout << sum[i] << " ";
    }
    

    for (int i = 0; i < x; i++)
    {

        int rr = r[q[i]] - r[p[i] - 1];
        int bb = b[q[i]] - b[p[i] - 1];
        int gg = g[q[i]] - g[p[i] - 1];

        //  cout << endl << endl;

        cout << rr << " " << bb << " " << gg << "\n";
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
