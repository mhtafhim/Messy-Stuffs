// competitive programming c++ template
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6;
const int mod = 1e9+7;

int  dp[maxN];

void solve(int cs)
{

    int n;
    cin >> n;
    
 
    dp[0] = 1;

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if ((i - j) >= 0)
                dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    //  for(int i =0;i<=n;i++) cout << dp[i] << " ";
    //  cout << endl;

    cout << dp[n] << endl;
}

int main()
{

    int t = 1;
    //  cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
