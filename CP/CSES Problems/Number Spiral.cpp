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
    cin >> t;
    for(int tc =1;tc<=t;tc++)
    {
        cin >> x >> y;
        if(x>=y)
        {
            if(x%2==0)
            {
                mx = x*x - (y -1);
            }
            else
            {
                x--;
                mx = (x*x+1) + (y -1);
            }

        }
        else
        {
            if(y%2==0)
            {
                y--;
                mx = (y*y+1) + (x-1);
            }
            else
            {
                mx = y*y - (x - 1) ;
            }
        }

        cout << mx << endl;

    }


   return 0;
}




