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

    ll n, mn = 1e18, inx;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        if (mn > tmp)
        {
            mn = tmp;
            inx = i;
        }
        v.push_back(tmp);
    }

    bool ok = true;

    for (int i = inx +1 ; i < n; i++)
    {
        if(v[i] < v[i-1]) 
        {
            ok = false;
            break;
        }
    }

    if(ok)
    {
        cout << inx << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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
