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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    ll suma = 0, sumb = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        sumb += b[i];
    }

    ll mna = *min_element(a.begin(), a.end());
    ll mxa = *max_element(a.begin(), a.end());

    ll mnb = *min_element(b.begin(), b.end());
    ll mxb = *max_element(b.begin(), b.end());

 //   cout << suma << " " << sumb << endl;

    if (mna < mxb)
    {
        if (k & 1)
            cout << max(suma, (suma - mna + mxb)) << endl;
        else
            cout << suma << endl;
    }
    else
    {
        if (k %2==0)
            cout << (suma - mxa + mnb)<< endl;
        else
            cout << suma << endl;
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
  
}