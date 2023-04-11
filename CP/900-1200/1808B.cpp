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
        lli n,m,temp,sum = 0,ans=0;
        cin >> n>>m;
        vector<int>vec[m];
        for(int i =0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>temp;
                vec[j].push_back(temp);
            }
        }

lli pref=0;
            for(int k=0; k<m; k++)
            {
                sort(vec[k].begin(),vec[k].end());
                pref=0;
                for(int i=0; i<n; i++)
                {
                    ans += 1LL * vec[k][i] * i - pref;
                    pref += vec[k][i];
                //    cout << ans << "    " << pref <<"    " <<vec[k][i] <<  endl;
                }


            }
            cout << ans << endl;



    }


    return 0;
}

