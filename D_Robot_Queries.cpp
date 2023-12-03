#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007

set<pair<int, int>> st;
bool thik = false;

void dfs(string s, int idx, int x, int y, int t1, int t2)
{

    if (x == t1 && y == t2)
        thik = true;

    //  cout << x << " " << y << endl;
    if (idx == s.length())
    {
        return;
    }

    if (s[idx] == 'R')
    {
        st.insert({x + 1, y});
        dfs(s, idx + 1, x + 1, y, t1, t2);
    }
    else if (s[idx] == 'L')
    {
        st.insert({x - 1, y});
        dfs(s, idx + 1, x - 1, y, t1, t2);
    }
    else if (s[idx] == 'U')
    {
        st.insert({x, y + 1});
        dfs(s, idx + 1, x, y + 1, t1, t2);
    }
    else if (s[idx] == 'D')
    {
        st.insert({x, y - 1});
        dfs(s, idx + 1, x, y - 1, t1, t2);
    }
}

void solve(int cs)
{
    ll n, q;
    cin >> n >> q;
    string ss;
    cin >> ss;

    while (q--)
    {
        // st.clear();
        ll x, y, l, r;
        cin >> x >> y >> l >> r;

        thik = false;
        string s = ss;
        reverse(s.begin() + l - 1, s.begin() + r);
        //      cout << s << endl;
        //     cout << *(s.begin() + l -1 ) << " " << *(s.begin() + r -1 ) << endl;

        //     st.insert({0, 0});
        dfs(s, 0, 0, 0, x, y);

        if (thik)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    fast;
    int t = 1;
    //   cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
