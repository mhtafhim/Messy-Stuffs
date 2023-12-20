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

    ll cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            cnt1++;
        else
            cnt2++;
    }

    ll cost = 0;

    //   cout << cnt1 << " " << cnt2 << endl;
    if (s.length() == 1)
        cout << 1 << endl;
    else if(cnt1 == cnt2)cout << 0 << endl;
    else
    {
        ll save = 0;
        for(int i = 0 ; i < s.length() ; i ++)
        {
            if(s[i] == '1')
            {
                cnt2--;
                if(cnt2 < 0) 
                {
                    save = i;
                    break;
                } 
            }
            else 
            {
                cnt1--;
                if(cnt1 < 0) 
                {
                    save = i;
                    break;
                } 
            }
        }
//cout << save << " ";
        cout << s.length() - save  << endl;
    }
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
