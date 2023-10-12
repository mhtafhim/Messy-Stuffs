#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define all(x) x.begin(), x.end()

void solve(int cs)
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(all(arr));

    ll l = 0, r = 1e9;
    ll mid, cnt = 0;

    while (l < r)
    {
        cnt = 0;
        mid = (l + r) / 2;
        int diff = 2 * mid + arr[0];

        for (int index = 0; index < n; index++)
        {
            if (diff < arr[index])
            {
                diff = 2 * mid + arr[index];
                cnt++;
            }
        }

        if (cnt > 2)
            l = mid + 1;
        else
            r = mid;
    }

    cout << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}
