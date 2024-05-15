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

    vector<char> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    bool ok = true;
    int cnt = 0;

    while (ok)
    {
        if (v.empty())
            break;

        int indx = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 'U')
            {
                indx = i;
                break;
            }
        }
    //     cout << indx << " ";

    //     for (auto x : v)
    //        cout << x;
    //     cout << endl;

    //    cout << (indx + 1 + n) % n << " " << (indx - 1 + n) % n << endl;

        if (indx != -1)
        {
            if (v.size() > 2)
            {
                if (v[(indx + 1 + n) % n] == 'U')
                    v[(indx + 1 + n) % n] = 'D';
                else
                    v[(indx + 1 + n) % n] = 'U';

                if (v[(indx - 1 + n) % n] == 'U')
                    v[(indx - 1 + n) % n] = 'D';
                else
                    v[(indx - 1 + n) % n] = 'U';
            }
            v.erase(v.begin() + indx);
             cnt++;
        }
        else
        {
            break;
        }
       
    }

  //  cout << cnt << endl;

    if (cnt & 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
