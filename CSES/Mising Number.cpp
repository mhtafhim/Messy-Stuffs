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
const lli mod=1000000007;

int main()
{

    fast

    lli t,n,i,x,mx,mn,f,j,s,r,y,c,m,k,z;
    t=1;
//   cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
        cin >>n;
        vector<bool> v(n+1,false);
        for(int i=1; i<n; i++)
        {
            cin >> x;
            v[x] = true;
        }


        for(int i=1; i<=n; i++)
        {
            if( v[i] == false)
            {
                cout << i << endl;
                break;
            }

        }


    }


    return 0;
}
