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
      vector<int> vec(n);
      mn = INT_MAX;
      int mnidx = 0;
      int mmx = 0;
      for(i=0;i<n;i++)
      {
          cin >> vec[i];

      }

      for(i =0;i<n-1;i++)
      {
          if(vec[i]>vec[i+1])
          {
              mmx = max(mmx,vec[i]);
          }
      }



      cout << mmx << endl;


    }


   return 0;
}

