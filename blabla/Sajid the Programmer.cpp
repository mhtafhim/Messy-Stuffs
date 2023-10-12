#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int n, p, q;

void solve(int cs)
{

    cin >> n >> p >> q;

    int vec[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    ll l = 0, r = 1e8;
    ll mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        // int f = func(vec, mid);
        //  cout << f << endl;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            //     cout << ceil(vec[i]*1.0 / mid) << endl;
            // cout << p << "  "<< ceil(arr[i] / mid) <<"  " << q <<endl;
            int tmp = ceil(vec[i] / (float)mid);
            //     cout << tmp << endl;
            cnt += tmp;
            //  cout << cnt << endl;
        }
        //  cout << l << " " << mid << " ";
        //   cout << r << " " << cnt << endl;
        if (cnt > q)
            l = mid + 1;
        else if (cnt < p)
            r = mid - 1;
        else if (cnt == p)
            r = mid - 1;
        else if (cnt >= p && cnt <= q)
            r = mid - 1;
    }
    if (mid == r)
        cout << -1 << endl;
    else
        cout << mid << endl;
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
