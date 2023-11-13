#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

ll dp[100000000];

void solve(int cs)
{

    dp[0] = 1;

    for (ll i = 1; i < 10000000; i++)
    {
        ll tmp = i * dp[i - 1];
        
        while (tmp % 10 == 0)
        {
            tmp = tmp / 10;
        }
  //      cout << i << " = " << tmp % 1000 << endl;
        dp[i] = tmp % 1000000;
    }

    int x;
    cin >> x;
    do
    {
  //      int tmp = dp[x];

        cout << dp[x]%10 << endl;

        cin >> x;

    } while (x != 0);
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
