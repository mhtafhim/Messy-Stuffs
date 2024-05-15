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
int tree_min[mx * 3];
int tree_max[mx * 3];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree_max[node] = arr[b];
        tree_min[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree_max[node] = max(tree_max[Left], tree_max[Right]);
    tree_min[node] = min(tree_min[Left], tree_min[Right]);
}

pair<int, int> query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return {INT_MIN, INT_MAX}; // বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return {tree_max[node], tree_min[node]}; // রিলেভেন্ট সেগমেন্ট
    int Left = node * 2;                         // আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    pair<int, int> p1 = query(Left, b, mid, i, j);
    pair<int, int> p2 = query(Right, mid + 1, e, i, j);
    return {max(p1.first, p2.first), min(p1.second, p2.second)}; // বাম এবং ডান পাশের যোগফল
}

void solve(int cs)
{
    ll n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i].second = i;
        cin >> v[i].first;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        arr[i + 1] = v[i].second+1;
       // cout << arr[i+1] << endl;
    }

    init(1, 1, n);

    int ans = INT_MAX;

    if(k == 1) 
    {cout << 0 << endl;
    return ;
    }

    for (int i = 1; i <n - k +1; i++)
    {
        auto q = query(1, 1, n, i, i + k - 1);
      //  cout << q.first << " " << q.second << endl;
        ans = min(ans, q.first - q.second);
    }

    cout << ans << endl;
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
