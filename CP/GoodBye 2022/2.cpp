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
        int sign = -1;
        int temp = 1;
        cin >>n;
        if(n==3)
        {
            cout << "NO" << endl;
        }
        else if(n%2!=0)
        {
            z = n/2 -1;
            cout << "YES" << endl;
             for(i =1;i<=n;i++)
            {

               if(i&1)
               {
                   cout << z << " ";
               }
               else
               {
                   cout << (z+1)*(-1) << " ";
               }

            }
            cout << endl;
        }
        else
        {
            cout << "YES" << endl;
            for(i =1;i<=n;i++)
            {

                cout << temp << " ";
                temp*=sign;
            }
            cout << endl;
        }


    }


   return 0;
}
