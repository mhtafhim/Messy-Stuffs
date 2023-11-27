#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


const int N = 1e6;
int table[N][20];
int ara[N], k = 20, n;

void sparse()
{
    int i, j;
    for (i = 0; i < n; i++)
        table[i][0] = ara[i];
    for (j = 1; j <= k; j++)
    {
        for (i = 0; i <= n - (1 << j); i++)
            // table[i][j]=max(table[i][j-1],table[i+(1<<(j-1))][j-1]);->max
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        
    }
}
int query(int L, int R)
{
    int j, ans = 1e9;
    for (j = k; j >= 0; j--)
    {
        if (L + (1 << j) - 1 <= R)
        {
            // ans=max(ans,table[L][j]);->max
            ans = min(ans, table[L][j]);
                L += 1 << j;
        }
    }
    return ans;
}

void solve(int cs)
{
    int q;
    cin >> n >> q;

    for(int i = 0 ;  i < n ; i ++)
    {
        cin >> ara[i];
    }
 

    sparse();


    while(q--)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        cout << query(a,b) << endl;
    }
  
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
