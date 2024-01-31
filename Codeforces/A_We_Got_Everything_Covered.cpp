#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

void print(int n, int k)
{
    if (n == 0)
        return;
    for (int i = 0; i < k; i++)
    {
        cout << (char)('a' + i);
    }
    print(n - 1, k);
}

void solve(int cs)
{

    int n, k;
    cin >> n >> k;

    print(n, k);
    cout << endl;
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
