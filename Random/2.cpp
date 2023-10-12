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
        int n;
        cin >> n;
        char  temp;

        int x=0,y=0;
        bool ok = false;

        for(int i =0;i<n;i++)
        {
            cin >>temp ;

            if(temp == 'U')
                y++;
            else if(temp=='D')
                y--;
            else if(temp=='R')
                x++;
            else if(temp=='L')
                x--;

       //     cout << x << " " << y << endl;
            if(x==1 && y==1)
            {
                ok = true;
            }

        }

        if(ok) cout <<  "YES" << endl;
        else cout <<  "NO" << endl;


    }


   return 0;
}

