// competitive programming c++ template
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define fill(a, b) memset(a, b, sizeof(a))
#define sp(x, y) fixed << setprecision(y) << x << " "
#define endl "\n"
#define debug(x) cout << x << endl
#define debug2(x, y) cout << x << " " << y << endl
#define debug3(x, y, z) cout << x << " " << y << " " << z << endl
#define debug4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define debugarr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define debugarr2(arr, n)       \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;
#define debugarr3(arr, n)        \
    for (int i = 1; i <= n; i++) \
        cout << arr[i] << " ";   \
    cout << endl;
#define debugvec(vec)     \
    for (auto x : vec)    \
        cout << x << " "; \
    cout << endl;
#define debugvec2(vec, n)       \
    for (int i = 0; i < n; i++) \
        cout << vec[i] << " ";  \
    cout << endl;
#define debugvec3(vec, n)        \
    for (int i = 1; i <= n; i++) \
        cout << vec[i] << " ";   \
    cout << endl;

// define vector input
#define vcin(vec, n)            \
    for (int i = 0; i < n; i++) \
        cin >> vec[i];
// define vector input using insert function
#define vcin2(vec, n)           \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        vec.pb(x);              \
    }

#define mx 100001
int arr[mx];
int tree[mx * 3];
bool ok = false;
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        ok = true;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if (ok)
        tree[node] = (tree[Left] % 3 == 0 && ok) + (tree[Right] % 3 == 0 && ok);
    else
        tree[node] = (tree[Left]) + (tree[Right]);
    ok = false;
    
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; // বাইরে চলে গিয়েছে
    if (i == j)
        return arr[i] % 3 == 0;
    else if (b >= i && e <= j)
        return tree[node]; // রিলেভেন্ট সেগমেন্ট

    int Left = node * 2; // আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
  //  debug2(p1, p2);
    return p1 + p2; // বাম এবং ডান পাশের যোগফল
}

void update(int node, int b, int e, int i, int newvalue)
{
    arr[i]+=1;
    if (i > e || i < b)
        return; // বাইরে চলে গিয়েছে
    if (b >= i && e <= i)
    {                    // রিলেভেন্ট সেগমেন্ট
        tree[node] += 1; // নতুন মান বসিয়ে দিলাম
        ok = true;
        return;
    }
    int Left = node * 2; // আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    if (ok)
        tree[node] = (tree[Left] % 3 == 0 && ok) + (tree[Right] % 3 == 0 && ok);
    else
        tree[node] = (tree[Left]) + (tree[Right]);
    ok = false;
}

void solve(int cs)
{
    int n, q;
    cin >> n >> q;

    init(1, 1, n);
  
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0)
        {
            for (int i = y + 1; i <= z + 1; i++)
            {
                update(1, 1, n, i, 1);
                
            }
       //     debug3(y,z,tree[1]);
        }
        else if (x == 1)
        {
            cout << query(1, 1, n, ++y, ++z) << endl;
        }
            
    }
}

int main()
{
    fast;
    int t = 1;
    //    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //  cout << "Case " << i << ":" << endl;
        solve(i);
    }

    return 0;
}
