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
        //cout << fixed << setprecision(30) << pi << endl;
        string s = "314159265358979323846264338327950288";
        string ss;
        cin >> ss;
        int cnt =0;
        for(int i =0 ;i<ss.length();i++)
        {
            if(s[i]==ss[i])
                cnt++;
            else
                break;
        }
        cout << cnt << endl;

    }


   return 0;
}

