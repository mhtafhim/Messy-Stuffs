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

        lli x,y,z;
        cin >> x>>y>>z;
        vector<int> v(x-1,0);

        cout << y-z << " ";

        int index =0;
        while(z!=0)
        {
            v[index]++;
            index++;
            if(index > (x-2))
                index = 0;
            z--;
        }


        for(auto it : v)
            cout << it << " ";
        cout << endl;

    }


   return 0;
}


