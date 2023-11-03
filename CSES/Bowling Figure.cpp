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

    int o;
    cin >> o;

    while (o--)
    {
        string ss;
        cin >> ss;
        int run = 0, w = 0;

        for (int i = 0; i < ss.length(); i++)
        {
            if (ss[i] == 'W')
            {
                w++;
            }
            else
            {
                run += (ss[i] - '0');
            }

           
        }
         cout << (int)(ss.length())/6 << '.'<< (int) (ss.length())%6 << ((int)(ss.length())>6 ? " Overs " : " Over ")<< run << (run > 1 ? " Runs " : " Run ") << w <<(w>1 ? " Wickets." : " Wicket.")<< endl;
    }
}

int main()
{
    fast;
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
