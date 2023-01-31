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

    lli t;
    t=1;
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {

        lli x,y,z,remain;
        cin >> x>>y>>z;

        cout << (y-z) << " ";
        lli a = x-1;
        lli b = (z+a-1)/a;
        a--;

        bool ok = false;
        if((z < b*a))
        {
            b--;
            remain = y-((b*a)+(y-z));
            a = a-remain;
            ok = true;
        }

        for(int i=0; i<a; i++)
        {
            cout << b << " ";
        }

        if(ok)
        {
            b++;
            for(int i=0; i<remain; i++)
            {
                cout << b << " ";
            }


         //   cout << (z - ( (b-1)*a + (b*remain-1) )) << endl;

        }
        else
            cout << (z - b*a) << endl;


    }


    return 0;
}

