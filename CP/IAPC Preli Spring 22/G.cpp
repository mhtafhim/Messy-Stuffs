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

long long int binpow2(long long int a, long long int b)
{
    a %= m;
    long long int res = 1;
    while (b > 0)
    {
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

    lli t,n,i,x,mx,mn,f,j,s,r,y,c,k,z;
    t=1;
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
        cin >> n;

      //  f = binpow2(4,n-1);
      //  cout << f << endl;

        //     x = (52 * binpow2(4,n-1) - 4*(n-1))%m;
        x = (48* binpow2(4,n-1) + 4*binpow2(3,n-1))%m;

        cout << x << endl;
    }


    return 0;
}
