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

    string ss;
    cin >> ss;

    cout << ss[0];
    for (int i = 1; i < n - 1; i++)
    {
        if ((ss[i] == 'b' || ss[i] == 'c' || ss[i] == 'd') && (ss[i + 1] == 'a' || ss[i + 1] == 'e'))
            cout << '.' << ss[i];
        else cout << ss[i];
    }
    cout << ss[n-1];
    cout << endl;
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
