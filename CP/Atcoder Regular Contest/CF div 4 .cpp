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
    for(int tc =1; tc<=t; tc++)
    {
        cin >> n;
        string ss;
        cin >> ss;

        vector<bool>cnt(26,false);
        int unik = 0,unik2=0;
        int mx = -1;

        for(int i = 0; i<n; i++)
        {
            cnt.assign(26,0);
            unik = 0,unik2=0;

            for(int j =0; j<i; j++)
            {
                cnt[ss[j]-'a'] = true;
            }

            for(int k=0; k<26; k++)if(cnt[k]==true)unik++;

            cnt.assign(26,0);

            for(int j =i; j<n; j++)
            {
                cnt[ss[j]-'a'] = true;
            }

            for(int k=0; k<26; k++)if(cnt[k]==true)unik2++;


            if(mx<unik+unik2)
                mx = unik+unik2;


        }

        cout << mx << endl;



    }


    return 0;
}

