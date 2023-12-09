#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18



vector<int> solve2(vector<int>& a, int score) {
  int n = a.size();
  vector<int> dp(n);

  for (int i = n - 1; i >= 0; --i) {
    if (a[i] <= score) {
      dp[i] = 1 + (i + 1 < n ? dp[i + 1] : 0);
    } else {
      dp[i] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] <= score) {
      score += a[i];
      a[i] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      dp[i] = max(dp[i], dp[i + 1]);
    }
  }

  return dp;
}



void solve(int cs){
    ll n ;
    cin >> n ;

    vector<ll> v(n) , ans;
    for(int i = 0 ; i < n ; i ++)cin >> v[i];

    ans = solve2(v,0);
    
}

int main(){
    fast;
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    } 
    return 0;
}
