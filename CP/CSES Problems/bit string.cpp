#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define memset(v,x) memset((v),x,(sizeof(v)))
using namespace std;
typedef long long int lli;
const lli m=1000000007;


long long binpow(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{

    fast

   lli t;
    t=1;
 //   cin >> t;
    for(int tc =1;tc<=t;tc++)
    {
        lli x;
        cin >> x;
        lli ans = binpow(2,x);

        cout << ans << endl;


    }


   return 0;
}
