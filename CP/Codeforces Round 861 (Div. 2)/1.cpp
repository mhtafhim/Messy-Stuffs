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

int lucky(int x)
{
    int mx=-1,mn = INT_MAX;
    int luck = 0;
    int rem;

    while(x>0)
    {
        rem = x%10;
        //  cout << rem << endl;
        x/=10;
        if(rem>=mx)
            mx = rem;
        if(rem<=mn)
            mn = rem;

        if(luck < (mx-mn))
            luck = mx-mn;
    }

    return luck;

}


int main()
{

    fast

    lli t;
    t=1;
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
        int l,r;
        cin >> l >> r;
        int mx=-1,temp,ans;

        if(l>r)swap(l,r);





        for(int i = l; i<=r; i++)
        {
            temp = lucky(i);
            if(temp>mx)
            {
                mx = temp;
                ans = i;
            }
            if(temp == 9)
            {
                ans = i;
                break;

            }

        }

        cout << ans << endl;





    }
     return 0;
}

