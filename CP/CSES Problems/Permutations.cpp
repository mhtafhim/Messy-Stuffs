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
    for(int tc =1;tc<=t;tc++)
    {
        cin >> n;
        if(n==1)
        {
            cout << 1 << endl;
            return 0;
        }
        if(n<4)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        if(n==4)
        {
            cout << "2 4 1 3" << endl;
            return 0;
        }
        if(n%2==0)
        {
            for(int i=1;i<=n/2;i++)
            {
                cout << i << " " << i+n/2 << " " ;
            }
        }
        else
        {
            for(int i=1;i<=n/2;i++)
            {
                cout << i << " " << i+(n+1)/2 << " " ;
            }
            cout << ((n+1)/2) <<endl;
        }

    }


   return 0;
}




