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
    for(int tc =1; tc<=t; tc++)
    {

       cin >> n;
   // n =5;
        lli alice = 0,bob = 0;
        lli cnt =0;

        cnt++;
        alice+=cnt;
        n-=cnt;

      //  cout << alice << "  && " << bob << endl;
        if(cnt>n)
        {
            alice+=n;
            cout << alice << " " << bob << endl;
            continue;
        }

        while(n>0)
        {

            cnt++;
            n-=cnt;
            bob+=cnt;

            if(cnt>=n)
            {
              //  cout << alice << "  && " << bob << endl;
                bob+=n;
                break;
            }
            cnt++;
            n-=cnt;
            bob+=cnt;

            if(cnt>n)
            {
             //   cout << alice << "  && " << bob << endl;
                alice+=n;
                break;
            }
            cnt++;
            alice+=cnt;
            n-=cnt;

            if(cnt>=n)
            {
              //  cout << alice << "  && " << bob << endl;
                alice+=n;
                break;
            }
            cnt++;
            n-=cnt;
            alice+=cnt;

             if(cnt>n)
            {
            //    cout << alice << "  && " << bob << endl;
                bob+=n;
                break;
            }




        }

        cout << alice << " " << bob << endl;



    }


    return 0;
}

