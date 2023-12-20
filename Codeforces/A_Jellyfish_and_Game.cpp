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

    // k = k % 4  + 4;

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

    if (k == 1)
    {
        suma = max(suma, suma - mna + mxb);
        cout << suma << endl;
    }
    else if (k == 2)
    {
        suma = max(suma, suma - mna + mxb);

        mxa = max(mxa, mxb);
        mnb = min(mna, mnb);

        suma = min(suma, suma - mxa + mnb);
    }
    else
    {
        suma = max(suma, suma - mna + mxb);

        mxa = max(mxa, mxb);
        mnb = min(mna, mnb);

        suma = min(suma, suma - mxa + mnb);

// cout << suma << " " ;
//         cout << mnb << " " << mxa << endl;

        if(k&1) 
        {
            suma = max(suma , suma + mxa - mnb);
            cout << suma << endl;
        }
        else 
        {
         //   suma = min(suma , suma - mxa + mnb);
            cout << suma << endl;
        }

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
