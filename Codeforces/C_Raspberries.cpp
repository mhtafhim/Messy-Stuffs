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

    int n, k;

    cin >> n >> k;

    vector<int> vec;
    int cnt = 0;
    bool ok = false;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0)
            cnt++;
        if (tmp % k == 0)
            ok = true;

        vec.push_back(tmp);
    }

    int mn = 100;
    if (ok)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            //     cout << (vec[i]>k? vec[i]%k : k-vec[i] ) << " ";

            mn = min(mn, (vec[i] > k ? k - (vec[i] % k) : k - vec[i]));
        }
        int mnn = 100;
        if (k == 4)
        {
            if (cnt >= 2)
                mnn = 0;
            else if (cnt == 1)
                mnn = 1;
            else
                mnn = 2;
        }
        //   cout << cnt1 << " " << cnt2 << endl;
        // cout << cnt << endl;
        cout << min(mn, mnn) << endl;
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
