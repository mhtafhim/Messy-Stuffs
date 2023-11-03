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

   // lli t,n,i,x,mx,mn,f,j,s,r,y,c,m,k,z;
   int  t=1;
    cin >> t;
    for(int tc =1;tc<=t;tc++)
    {
      int x;
      cin >> x;

      float sum=0;

      for(int i =1;i<x;i++)
      {
          float temp;
          cin >> temp ;
          sum+=temp;
      }

      float ans = (28 - sum)/(9-x);

    //  cout << setprecision(2) << ans << endl;

      if(ans <= 4)
      {
          cout << "YES" << endl <<setprecision(2) <<  ans << endl;
      }
      else
      {
          cout << "NO"<< endl ;
      }




    }


   return 0;
}

