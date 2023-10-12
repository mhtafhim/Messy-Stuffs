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
    vector<pair<int, int>> vec;
    vector<int> zeros;
    bool allzero = true;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp < 10)
        {
            vec.push_back({tmp * 10 + tmp, tmp});
        }
        else
        {
            vec.push_back({tmp, tmp});
        }

        if (tmp % 10 == 0)
        {
            zeros.push_back(tmp);
        }

        if (tmp != 0)
            allzero = false;
    }

    if (allzero)
    {
        cout << 0 << endl;
        return;
    }

    sort(vec.begin(), vec.end(), greater<pair<int, int>>());

    sort(zeros.begin(), zeros.end());

    bool tut = false;

    for (int i = 0; i < n; i++)
    {
        if (!zeros.empty())
        {
            if (zeros[0] != vec[i].second || tut)
            {
                cout << vec[i].second;
            }
            else
                tut = true;
        }
        else
        {
            cout << vec[i].second;
        }
    }
    if (!zeros.empty())
        cout << zeros[0];

    return;
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
