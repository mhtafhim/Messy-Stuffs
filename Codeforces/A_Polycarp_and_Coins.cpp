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
    int n;
    cin >> n;

    ll div = n / 3;

    if ((div * 1 + div * 2) == n)
    {
        cout << div << " " << div << endl;
    }
    else if (((div + 1) * 1 + div * 2)==n)
    {
        cout << div + 1 << " " << div << endl;
    }
    else
    {
        cout << div << " " << div + 1 << endl;
    }
}

//2*1 + 1*2 = 

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
