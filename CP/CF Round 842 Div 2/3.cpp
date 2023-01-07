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
          vector<lli> vec(n);
          vector<lli> counter(n+1,0);

          bool ok =true;
          for(i = 0 ;i<n;i++)
          {
              cin >> vec[i];
              counter[vec[i]]++;

          }

           for(i = 1 ;i<=n;i++)
          {
              if(counter[i]==0)
              {
                  c++;
                  m = i;
              }
              if(counter[i]>1)
              {
                  s++;
                  if(s>0 && c!=0 && i !=n)
                  {
                      ok = false;
                      break;
                  }
                  if(s>1)
                  {
                      k = i;
                      break;
                  }

              }
              if(counter[i]>2)
              {
                  r++;
              }

          }
          if(!ok)
          {
              cout << "NO" << endl;
          }
          else if(r>0 || s>1)
          {
              cout << "NO" << endl;
          }
          else if(s==0)
          {
              cout << "YES"<< endl;
              for(auto it : vec )
              {
                  cout << it << " " ;
              }
              cout << endl;
              for(auto it : vec )
              {
                  cout << it << " " ;
              }
          }
          else if(ok)
          {
              cout << "YES" << endl;
              for(i = 0 ;i<n;i++)
              {
                  if(counter[i+1]==1)
                  cout << vec[i] << " ";
                  else
                    cout << m ;
              }
              cout << endl;
              for(i = 0 ;i<n;i++)
              {

              }

          }
    }


   return 0;
}
