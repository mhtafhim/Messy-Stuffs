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

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int mx = -1;

    mx = max(mx , v[0]);
    for (int i = 1; i <n; i++)
    {
        mx = max(mx,v[i]-v[i-1]);
    
    }

    mx = max(mx, 2 * (x - v[n-1]));

    cout << mx << endl;


}

int main()
{
    fast;
    int t = 1;
      cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
