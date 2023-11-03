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
        lli n,m;
        cin >> n>>m;
        vector<char>v(n),vv(m);
        bool ok = true;
        bool same = false;
        int cnt =0;

        for(int i =0; i<n; i++)
            cin >> v[i];

        for(int i =0; i<m; i++)
            cin >> vv[i];


        if(v[n-1]!=vv[m-1])
        {
            for(int i =0; i<n-1; i++)
            {
                if(v[i]==v[i+1])
                {
                    cnt++;
                }

            }

            for(int i =0; i<m-1; i++)
            {
                if(vv[i]==vv[i+1])
                {
                    cnt++;
                }

            }

            if(cnt > 1)
            {
                cout << "No" << endl;
            }
            else
                cout << "Yes" << endl;

        }
        else
        {
            for(int i =0; i<n-1; i++)
            {
                if(v[i]==v[i+1])
                {
                    ok = false;
                    break;
                }

            }

            for(int i =0; i<m-1; i++)
            {
                if(vv[i]==vv[i+1])
                {
                    ok = false;
                    break;
                }

            }

            if(ok)
                cout << "yes" << endl;
            else
                cout << "No" << endl;
        }





    }


    return 0;
}

