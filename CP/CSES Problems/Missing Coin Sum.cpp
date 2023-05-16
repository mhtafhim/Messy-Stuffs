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
       int x;
       cin >> x;

       vector<int> v;

       for(int i =0;i<x;i++)
       {
        int temp;
        cin >> temp;
        v.pb(temp);
       }

       sort(v.begin(),v.end());
     

        lli sum = 0;
        lli ans =0;
       for(int i =0;i<x;i++)
       {
         if(sum+1 < v[i])
         {
           // ans =sum+1;
            break;
         }
         else
         {
            sum+=v[i];
         }
       }

       cout << sum+1<< endl;




    }


    return 0;
}
