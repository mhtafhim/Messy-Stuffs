#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


bool sortBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;
}

void solve(int cs)
{
    int n, k;
    cin >> n >> k;

    map<int, int> mp;


    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        mp[b] += c;
    }


    ll sum = 0, cnt = 0;


    std::vector<std::pair<int, int>> vec(mp.begin(), mp.end());


    std::sort(vec.begin(), vec.end(), sortBySecond);

    // for (auto x : vec)
    // {
    //    cout << x.first << " " << x.second << endl;
    // }


    for (auto x : vec)
    {
        cnt++;
        sum += x.second;

        if (n == cnt)
            break;
    }


    cout << sum << endl;

// cout << endl;

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
