#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

#define mx 100001
int arr[mx];
int tree[mx * 3];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = __gcd(tree[Left], tree[Right]);
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; // বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; // রিলেভেন্ট সেগমেন্ট
    int Left = node * 2;   // আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return __gcd(p1, p2); // বাম এবং ডান পাশের যোগফল
}



void solve(int cs)
{
    ll n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    init(1, 1, n);

    ll mxx = -1;

    for (int i = 0; i - k <= n; i++)
    {
        ll tmp1 = query(1, 1, n, 0, i);
        ll tmp2 = query(1, 1, n, k + i+1, n+1);
        mxx = max(mxx, __gcd(tmp1,tmp2 ));
    }

    

    cout << mxx << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
