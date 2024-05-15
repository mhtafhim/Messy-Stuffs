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

    deque<ll> a;
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(a.begin(), a.end());
    sort(v.begin(), v.end());

    int ans = 0;
    int indx = 0;
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        //   cout << a.at(i) << " " << v[i] << endl;
        if (a.at(i) > v[i])
            ok = false;
    }

    while (!ok)
    {

        ans++;
        a.push_front(1);
        a.pop_back();
        ok = true;
        for (int i = 0; i < n; i++)
        {
            //   cout << a.at(i) << " " << v[i] << endl;
            if (a.at(i) > v[i])
                ok = false;
        }
    }

    cout << ans << endl;
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
