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
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    map<int, int> mp;
    int start = 0, end = 0;
    int mx = 1;

    for (int i = 0; i < n; i++)
    {
        //      cout << vec[i] << " = " << i << " ;" ;
        if (mp.count(vec[i]))
        {
            int tmp = mp[vec[i]];
            //     cout << "tmp=" << tmp + 1 <<  " ;";
            // if(start > tmp +1 )
            // {
            //     start = tmp + 1;
            // }
            start = max(start, tmp + 1);

            mp[vec[i]] = i;

           // mx = max(mx, i - start + 1);
        }
        else
        {
            mp[vec[i]] = i;

          //  mx = max(mx, i - start + 1);
            
        }
         mx = max(mx, i - start + 1);
      //   cout << start << " " << i << "  " << i - start + 1 << " " << mx << endl;
    }

    cout << mx << endl;
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
