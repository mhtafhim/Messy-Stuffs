#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

ll sum = INT_MIN;

set<vector<ll>> st;

void calculate(vector<ll> v)
{

    if (v.size() <= 1)
    {
        sum = max(sum, v[0]);
        return;
    }

    if (st.count(v))
        return;

    vector<ll> v1 = v;
    reverse(v.begin(), v.end());
    ll temp_sum = v1[0];
    ll temp_sum2 = v[0];
    vector<ll> v3, v4,v5,v6;

    for (int i = 1; i < v1.size(); i++)
    {
        //   cout << v1[i] - v1[i - 1] << " ";
        temp_sum += v1[i];
        temp_sum2 += v[i];
        v3.push_back(v1[i] - v1[i - 1]);
        v4.push_back(v[i] - v[i - 1]);
    }

//     v5 = v3;
//     v6 = v4;


//   //  sort(v3.begin(), v3.end());
//   //  sort(v4.begin(), v4.end());

//     bool f1 = true, f2 = true;




    // cout << "dir -> ";
    // for (int i = 0; i < v3.size(); i++)
    // {
    //     cout << v3[i] << " ";
    // }
    // cout << endl;
    // cout << "rev -> ";
    // for (int i = 0; i < v3.size(); i++)
    // {
    //     cout << v4[i] << " ";
    // }
    // cout << endl;

    // cout << endl;

    sum = max(sum, temp_sum);
    sum = max(sum, temp_sum2);

    st.insert(v);


    calculate(v3);
    calculate(v4);
}

void solve(int cs)
{
    st.clear();
    sum = INT_MIN;
    int n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    calculate(v);

    cout << sum << endl;
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
