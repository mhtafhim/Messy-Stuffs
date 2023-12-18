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

    ll q;
    cin >> q;

    vector<ll> v(30);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            v[b]++;
        }
        else
        {
            // cout << b << endl;
            for (int i = 29; i >= 0; i--)
            {
                for (int j = v[i]; j > 0; j--)
                {
                   // cout << (1ll << i) << endl;
                    if (b >= (1ll << i))
                    {
                       
                        b -= (1ll << i);
                    }
                    else
                    {
                        break;
                    }
                }
                // cout << b << endl;

            }



            if (b)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}

int main()
{
    fast;
    int t = 1;
    //   cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
