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

void solve(int cs)
{

    int n, m;
    cin >> n >> m;

    vi points(m);
    vcin(points, m);
    int mx = 0;

    vector<int> unsolved[n];
    vector<int> tp(n);
    //   debugvec(points);

    for (int i = 0; i < n; i++)
    {
        string ss;
        cin >> ss;
        for (int j = 0; j < sz(ss); j++)
        {
            if (ss[j] == 'x')
            {
                unsolved[i].pb(-points[j]);
            }
            else
            {
                // debug2(tp[i],points[i])
                tp[i] += points[j];
            }
            
        }
        tp[i] += i + 1;
        mx = max(mx, tp[i]);
    }
    //   cout << mx << endl << endl;

    for (int i = 0; i < n; i++)
    {
        sort(all(unsolved[i]));
        //  debugvec(unsolved[i]);
        if (tp[i] >= mx)
        {
            cout << 0 << endl;
            continue;
        }

        //   debug2(mx,tp[i]);
        int cnt = 0;
        int ntp = mx - tp[i];
        int inx = 0;

        while (ntp > 0)
        {
            ntp -= (-unsolved[i][inx]);
            cnt++;
            inx++;
        }
        cout << cnt << endl;
    }
}

int main()
{
    fast;
    int t = 1;
    //  cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
