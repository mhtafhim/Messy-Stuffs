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
    int t;
    t=1;
 //   cin >> t;
    for(int tc =1;tc<=t;tc++)
    {
        lli n;
        cin >> n;
        vector<int> vec;
        for(int i =0;i<n;i++)
        {
            int temp;
            cin >> temp;
            vec.pb(temp);
        }
        sort(all(vec));
        reverse(all(vec));

        lli sum1=0,sum2=0;

        for(int i =0;i<n;i++)
        {
            lli t1 = sum1+vec[i];
            lli t2 = sum2+vec[i];

            if(abs(t1-sum2) < abs(t2-sum1) )
            {
                sum1+=vec[i];
              //  cout << "sum1 = " << sum1 << endl;
            }
            else
            {
                sum2+=vec[i];
              //  cout << "sum2 = " << sum2 << endl;
            }

        }

        cout << abs(sum1-sum2) << endl;


    }


   return 0;
}


