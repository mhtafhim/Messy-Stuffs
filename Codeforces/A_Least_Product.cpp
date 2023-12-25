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
    ll n;
    cin >> n;

    vector<ll> v(n);

    ll cnt = 0;
    bool zero = false;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < 0)
            cnt++;
        if(v[i] == 0)zero = true;
    }

//cout << "cnt = " << cnt << endl;

    if (cnt & 1 or zero)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
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
