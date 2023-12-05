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

    string s;
    cin >> s;

    for (int i = 0; i < 8; i++)
    {
        string tmp1 , tmp2;

        
        if (s[1] != (char)('1' + i))
        {
            cout << s[0] << (char)('1' + i) << endl;
           

        }

        if (s[0] != char('a' + i) )
        {
            cout <<  char('a' + i)  << s[1] << endl;

        }
        //    cout << ('a' + 1) + s[1] << endl;
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
