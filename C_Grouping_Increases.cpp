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

    vector<ll> v(n), a, b;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll cnt = 0;

    //  cout << "somossa ki ? " << endl;

    //   ll mn = v[0];
    a.push_back(v[0]);
    for (int i = 0; i < n; i++)
    {
        if (a[a.size() - 1] >= v[i])
        {
            a.push_back(v[i]);
        }
        else
        {
            b.push_back(v[i]);
        }
    }

    
    if (b.size() > 1)
        for (int i = 0; i < b.size() - 1; i++)
        {
            if (b[i] < b[i + 1])
                cnt++;
        }

    cout << cnt << endl;
    // cout << max((ll)0,cnt-1) << endl;
    // return ;
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

// 8 1 8 2 2 7 4 3


// 1 8   2 7

// 8 1 






// 8 2 1 1    8 7 4 3

//     8 2 1 1 8 7 4 3

//     8 2 3 1 1 7 4 3

//     8 2 1 1 3 7 4 3




// 1 2 3 4 5 6

// 1 2 3   4 5 6

// 10 13 15 8 18 9 2

//13  18 9 2   10 
// 10 13 8 2      15 18 9

// 10 8 9 2      15 8 18 9

//  10  3 2

//  5 4 3 1 2

//  5 3 1  4 2


// 10 13 15 28 18 9 2




// 10 13
// 13 15
// 15 18





// 13  9 2    

// 10 15 28 18


// 100 51  2 50 3 49 4 48



2 50  3 49 4 48





