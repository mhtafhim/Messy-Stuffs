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
    for(int tc =1; tc<=t; tc++)
    {
        int n;
        cin >> n;
        vector<int> vec(n);

        for(int i =0; i<n; i++)
            cin >> vec[i];

        bool flag = false;

        for(int k=0; k<n-1; k++)
        {

            for(int i =0; i<n-1; i++)
            {
                if(vec[i]<0)
                {
                    if(vec[i]*(-1) >= vec[i+1])
                    {
                        vec[i]*=(-1);
                        vec[i+1]*=(-1);
                        flag = true;
                    }
                }
            }


            if(!flag) break;

        }



        lli sum =0;

        for(int i =0; i<n; i++)
        {
            sum+= vec[i];
        }

        cout << sum << endl;


    }


    return 0;
}
