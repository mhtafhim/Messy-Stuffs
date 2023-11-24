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
 //   cin >> t;
    for(int tc =1;tc<=t;tc++)
    {
        lli n;
        cin >> n;
        vector<bool>included(n+1,false);
        lli num = (n*(n+1))/2;

        if(num&1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;

            vector<int> ans,ans2;
            lli remain = num/2;
         //   cout << remain <<"remain debug " <<endl;
            lli index = n;
            lli cnt=0;
         //   lli sum=0;

            while(remain>0)
            {
                if(index<=remain)
                {
                   included[index]=true;
                   ans.pb(index);
                   remain-=index;
                //   sum+=index;
                   index--;
                   cnt++;
                   if(remain==0)
                    break;

                }
                else
                {
                    ans2.pb(index);
                    index--;

                }


            }
         //   cout << sum << "sum debug" << endl;
            cout << cnt<< endl;
            for(auto it:ans)
                cout << it << " " ;

            cout << endl;
            cout << n-cnt << endl;
            for(int i=1;i<=n;i++)
            {
                if(!included[i])
                    cout << i << " ";

            }
            cout << endl;


        }


    }


   return 0;
}

