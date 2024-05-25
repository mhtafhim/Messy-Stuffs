#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

ll dp[1000000];

void solve(int cs)
{
    ll n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {

        dp[i] = 0;

        for (int j = 1; j <= 6; j++)
        {

            if (i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j])%mod;
            }
        }
    }

   
    cout << dp[n];
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
