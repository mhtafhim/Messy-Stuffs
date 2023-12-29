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

    vector<ll> v(n),preff(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i & 1)
            v[i] = -v[i];
    }

    set<ll> st;

    preff[0] = v[0];
    st.insert(preff[0]);
    for(int i = 1 ; i < n ; i ++)
    {
        preff[i] = preff[i-1] + v[i];
     //   cout << preff[i] << " ";
        if(st.count(preff[i]) || preff[i]==0)
        {
            cout << "YES" << endl;
            return;

        }
        else
        {
            st.insert(preff[i]);
        }
    }

//cout << endl;
  

    cout << "NO" << endl;
    return;
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
