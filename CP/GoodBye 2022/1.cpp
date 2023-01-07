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
        cin >> n;
        string ss;
        cin >> ss;
        bool ok = false;
        x = ss.length();

        for(i=0;i<x-1;i++)
        {
            if(ss[i]=='L' && ss[i+1]=='R')
            {
                cout << i+1 << endl;
                ok = true;
                break;
            }
            else if(ss[i]=='R' && ss[i+1]=='L')
            {
                cout << 0 << endl;
                ok = true;
                break;
            }
        }

        if(!ok)
            cout << -1 << endl;




    }


   return 0;
}
