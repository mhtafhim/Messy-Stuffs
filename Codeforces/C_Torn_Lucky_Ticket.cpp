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

    map<int, int> mp[6];
    ll cnt = n;

    vector<pair<int,int>> vec;
    vector<string> ss;

    for (int k = 0; k < n; k++)
    {
        string tmp;
        cin >> tmp;
        vec.push_back({tmp.size(),k});
        ss.push_back(tmp);
    }

    sort(vec.begin(),vec.end());
    for(auto u : vec)
    {

        string tmp;
        tmp = ss[u.second];

        int sz = tmp.size();
        int sum = 0;

        for (int i = 0; i < sz; i++)
        {
            sum += (tmp[i] - '0');
        }

        int sum1 = sum, sum2 = sum;
      //  cout << "sum = " << sum1 << endl;

       
        //    cnt += mp[sz][sum];

        for (int i = 0; i < sz; i++)
        {
            int inx = (sz - (2 * i));

            if (inx < 0)
                continue;

            cnt += mp[inx][sum1];
            cnt += mp[inx][sum2];

        //    cout << inx << " " << sum1 << " mp[inx][sum1] = " << mp[inx][sum1] << endl;

        //    cout << inx << " " << sum2 << " mp[inx][sum2] = " << mp[inx][sum2] << endl;

            sum1 -= 2*(tmp[i] -'0');
            sum2 -= 2*(tmp[sz - 1 - i] - '0');
        }

         mp[sz][sum]++;
      //   cout << endl;
    }

    cout << cnt << endl;
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
