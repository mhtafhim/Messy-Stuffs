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

void solve(int p)
{
    ll n;
    cin >> n;
    vector<ll> vec;
    for (int i = 0; i < n - 1; i++)
    {
        ll tmp;
        cin >> tmp;
        vec.pb(tmp);
    }

    ll sum = n * (n + 1) / 2;
    bool ok = true;

    ll sum2 = vec[0];
    set<ll> st;
    ll big = n + n - 1;

    //  st.insert(vec[0]);

    if (vec[n - 2] > sum)
        ok = false;
    // cout << vec[n-2] << endl;
    else if (vec[n - 2] != sum)
    {
        vec.pb(sum);
    }

    int cnt = 0;
    vl vec2(n + 1);
    ll outsider = -1;

    if (vec[0] <= n)
        vec2[vec[0]]++;
    else
        outsider = vec[0];

    for (int i = 1; i < vec.size(); i++)
    {
        ll dif = vec[i] - vec[i - 1];
        if (dif <= n)
            vec2[dif]++;
        else
            outsider = dif;

        //  if(vec2[dif]>1)cnt++;
    }
//    debugvec(vec2);
    ll ans = 0;
   // if (outsider == -1 && ok)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (vec2[i] == 0)
                ans += i;
            if (vec2[i] == 2)
                outsider = max(i,outsider);
            else if (vec2[i] > 2)
                ok = false;
        }
    }

  //  debug2(outsider,ans);

    if ((outsider != ans) && outsider !=-1)
        ok = false;

    (ok ? cout << "YES" : cout << "NO");

    cout << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve(t);
    return 0;
}
