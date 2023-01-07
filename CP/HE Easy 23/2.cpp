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


void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{

    fast

    __int128 t,n,i,x,mx,mn,f,j,s,r,y,c,m,k,z;
    t=1;
//   cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
        bool ok =false;
        string ss;
        cin >> ss;
        f = ss.length();
        vector<int> loc;
        for(i=f-1; i>=0; i--)
        {
          //  cout << "counting" << endl;
            if(ss[i]=='X')
                loc.push_back(i);
        }
        m=0;

        for(j = 9 ; j>0 ; j--)
        {

            for(k = 9 ; k>=0 ; k--)
            {
                m++;
                z=0;
                mx=1;
                for(i=f-1; i>=0; i--)
                {

                    if(i==loc[0])
                    {
                    //    cout << k*mx << endl;
                        z += k*mx;
                        mx*=10;
                        continue;
                    }
                    if(i==loc[1])
                    {
                    //    cout << j*mx << endl;
                        z += j*mx;
                        mx*=10;
                        continue;
                    }
                 //   cout << (ss[i]-48)*mx << endl;
                    z += (ss[i]-48)*mx;
                    mx*=10;
                }

                if(z%3==0 && z%9!=0)
                {
                    print(z);
                    ok = true;
                    break;
                }


            }
            if(ok)
            {
                break;
            }

        }

    //    cout << m << endl;


    }


    return 0;
}
