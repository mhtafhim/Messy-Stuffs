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
          int points[n];
          string s1;
          string s2;

          z = 0;
          m =0,k = 0,s = 0,r = 0;


          for (int i =0;i<n ;i++ )
          {
              cin >> points[i];
              z+= points[i];
          }

           int remainingA = z;
           int remainingB = z;

          cin >> s1;
          cin >> s2;

           for (int i =0;i<n ;i++ )
          {
              if(s1[i]=='S')
              {
                  s += points[i];
              }
               if(s2[i]=='S')
              {
                  r += points[i];
              }
          }

          if(s==r)
          {
              cout << "Draw" << endl;
              continue;
          }


          for (int i =0;i<n ;i++ )
          {

              if(remainingA < k && remainingA < z)
              {
                cout << i-1 <<" "<< i-1 << endl;
                  break;
              }

              z -= points[i];
              if(s1[i]=='S')
              {
                  m+= points[i];
              }


              if(remainingB < m && remainingB < z)
              {
                cout << i <<" "<< i-1 << endl;
                  break;
              }
              else if(s2[i]=='S')
              {
                  k+= points[i];
              }



          }




    }


   return 0;
}
