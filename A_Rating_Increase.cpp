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

    //   string s = "10" , ss = "2";
    string ss;
    cin >> ss;

    ll num = stoi(ss);
    string s;
    int inx = ss.length() - 1;
    ll tmp;
    while (inx >= 0)
    {
        s += ss[inx];
        char t = ss[inx];
        inx--;
        num /= 10;
        if (t != '0')
        {
            reverse(s.begin(), s.end());
            tmp = stoi(s);
            if (tmp != num and tmp > num)
                break;
            else
                reverse(s.begin(), s.end());
        }
        //
    }
  //  cout << s << endl;

     if(inx == -1)cout << -1 << endl;
     else cout << num << " "<< tmp << endl;
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
