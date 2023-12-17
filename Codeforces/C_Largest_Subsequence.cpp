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

    string s;
    cin >> s;

    vector<int> a;
    vector<char> aa;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a.empty() || s[i] >= s[a.back()])
        {
            a.push_back(i);
            aa.push_back(s[i]);
        }
    }
    

    reverse(a.begin(),a.end());
    int j = 0 ;
    while(j < a.size() and s[a[0]] == s[a[j]])
    {
        j++;
    }

    
    ll ans = a.size() - j;

    int sz = a.size();

    for(int i = 0 ; i < sz/2 ; i ++)
    {
        swap(s[a[i]], s[a[sz-i-1]]);
    }

    if(!is_sorted(s.begin(),s.end()))ans = -1;

 //   cout << s << endl;


    cout << ans << endl;
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
