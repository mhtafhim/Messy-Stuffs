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
    for(int tc =1;tc<=t;tc++)
    {

        lli a,b,c,d,x,y,z,w;
        cin >> a>>b>>c>>d;

        if(a==0)
        {
            cout << 1 << endl;
        }
        else if(a > (b+c+d))
        {
            cout << a+b+c+d << endl;
        }
        else if(a!=0 && b ==0 && c==0 && d==0)
        {
            cout << a << endl;
        }
        else if(a==0 && b==0 && c==0 && d!= 0)
        {
            cout << 1 << endl;
        }
        else if(b==0 && c==0)
        {
            if(a>=d)
                cout << (a+d) << endl;
            else
                cout << (2*a)+1 << endl;
        }
        else if(b==0 || c==0)
        {
            if(d==0 && a>=max(b,c))
            {
                cout << a+ max(b,c) << endl;
            }
            else if(d==0)
            {
                cout << 2*a+1 <<endl;
            }
            else if(a>max(b,c))
                cout << (2*a)+1 << endl;
            else
                cout << a+ max(b,c) + 1 << endl;
        }
        else
        {
            w = min(b,c);
            z = 2*a;
            y = ((w-a)/(2*a));
            x = z + y*z + z*(y+1) + 1 + ((w-a)%z)*2;
            cout << x << endl;
        }


    }


   return 0;
}
