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

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    set<int> st;



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
        //    cout << b[i]+a[j] << " ";
            if(!st.count(b[i]+a[j]))
            {
                st.insert(b[i]+a[j]);
                a.erase(a.begin()+j);
            }
        }
    //    cout << endl;
        if(st.size()>=3)
        {
            break;
        }

    }


    if(st.size()>=3)cout << "YES" << endl;
    else cout << "NO" << endl;

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
