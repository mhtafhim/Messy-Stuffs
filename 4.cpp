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
        cin >>n;

        string ss;
        cin >> ss;

        vector<int> cnt(n+1,0);
        vector<int>cnt2(n+1,0);
        set<char> st;

        int maxInd=-1 , mx = -9999999;
        st.insert(ss[0]);
        cnt[1] = 1;
        cnt2[cnt[1]] +=1;
        for(int i =1;i<n;i++)
        {
           if(!st.count(ss[i]))
           {
               st.insert(ss[i]);
               cnt[i+1] = cnt[i]+1;
               cnt2[cnt[i+1]] +=1;


           }
           else
           {
               cnt[i+1] = cnt[i];
               cnt2[cnt[i+1]] +=1;
               if(cnt2[cnt[i+1]] >= mx)
               {
                   mx = cnt2[cnt[i+1]];
                   maxInd = cnt[i+1];
               }
           }

        }

        for(int i =1;i<=n;i++)
        {
            cout << cnt[i] << " ";
        }
        cout << endl;
        for(int i =1;i<=n;i++)
        {
            cout << cnt2[i] << " ";
        }

        cout << endl;
        cout << maxInd << endl;








    }


   return 0;
}

