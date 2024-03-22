#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> nxt(n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        nxt[i] = a[i] == a[i + 1] ? nxt[i + 1] : i + 1;
    //    cout << nxt[i] << " ";
    }

 //   for(auto x : nxt)cout << x << " ";
    

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        if (nxt[l] < r)
        {
            cout << l + 1 << " " << nxt[l] + 1 << endl;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }

    cout << "\n";
}


int main(){
    fast;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    } 
    return 0;
}
