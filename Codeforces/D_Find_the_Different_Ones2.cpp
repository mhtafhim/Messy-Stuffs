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
pair<ll, ll> maxtree[mx * 3], mintree[mx * 3];

void init1(int node, int b, int e)
{
    if (b == e)
    {
        maxtree[node].first = arr[b];
        maxtree[node].second = b;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init1(Left, b, mid);
    init1(Right, mid + 1, e);
    maxtree[node] = max(maxtree[Left], maxtree[Right]);
}

pair<ll, ll> query1(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return {0, 0}; // বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return maxtree[node]; // রিলেভেন্ট সেগমেন্ট
    int Left = node * 2;      // আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    pair<ll, ll> p1 = query1(Left, b, mid, i, j);
    pair<ll, ll> p2 = query1(Right, mid + 1, e, i, j);
    return max(p1, p2); // বাম এবং ডান পাশের যোগফল
}

void init2(int node, int b, int e)
{
    if (b == e)
    {
        mintree[node].first = arr[b];
        mintree[node].second = b;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init2(Left, b, mid);
    init2(Right, mid + 1, e);
    mintree[node] = min(mintree[Left], mintree[Right]);
}

pair<ll, ll> query2(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return {INT_MAX, INT_MAX}; // বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return mintree[node]; // রিলেভেন্ট সেগমেন্ট
    int Left = node * 2;      // আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    pair<ll, ll> p1 = query2(Left, b, mid, i, j);
    pair<ll, ll> p2 = query2(Right, mid + 1, e, i, j);
    return min(p1, p2); // বাম এবং ডান পাশের যোগফল
}

void solve(int cs)
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    //  std::fill(std::begin(arr), std::end(arr), 0);
    //   for (int i = 0; i <= n; i++)
    //       arr[i] = 0;
    init1(1, 1, n);
    init2(1, 1, n);

    int q;
    cin >> q;
    // cout << q << endl;
    while (q--)
    {

        int a, b;
        cin >> a>>  b;
      //     cout << a << " " <<b  <<  endl;
        auto x = query1(1, 1, n, a, b);
        auto y = query2(1, 1, n, a, b);
        if (x.first != y.first)
        {
            ll tmp = min(x.second,y.second);
            ll tmp2 = max(x.second,y.second);
            cout << tmp << " " << tmp2 << endl;
        }

        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }

    cout << endl;
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
