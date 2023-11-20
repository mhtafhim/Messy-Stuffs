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

    int n, k;
    cin >> n >> k;

    string ss;
    cin >> ss;

    int cnta = 0, cntb = 0;

    for (int i = 0; i < ss.length(); i++)
    {
        if (ss[i] == 'B')
            cntb++;
    }

    cnta = ss.size() - cntb;

    if(cntb == k) 
    {
        cout << 0  << endl;
        return;
    }

    if (cntb < k)
    {
        for (int i = 0; i < ss.length(); i++)
        {
            if (ss[i] == 'A')
                cntb++;

            if(cntb == k)
            {
                cout << 1 << endl;
                cout << i+1 << " B" << endl;
                return;
            }
        }

    }
    else
    {
         for (int i = 0; i < ss.length(); i++)
        {
            if (ss[i] == 'B')
                cntb--;

        //    cout << cntb << " what\n";

            if(cntb == k)
            {
                 cout << 1 << endl;
                cout << i+1 << " A" << endl;
                return;
            }
        }
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
