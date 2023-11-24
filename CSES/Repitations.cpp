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
        string ss;
        cin >> ss;
        char temp = ss[0];
        s =1;
        mx = 0;

        for(i =1; i<ss.length(); i++)
        {
            if(temp==ss[i])
            {
                s++;
            }
            else
            {
                if(mx<s)
                {
                    mx = s;
                 //   cout << mx << endl;
                }
                s=1;
                temp = ss[i];
            }
        }
        if(mx<s)
        {
            mx = s;
        }

        cout << mx << endl;



    }


    return 0;
}
