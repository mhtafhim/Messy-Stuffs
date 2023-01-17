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
    for(int tc =1;tc<=t;tc++)
    {
        cin >> n;
        string ss;
        cin >> ss;
        set<char> st;
        for(int i =0;i<ss.length();i++)
        {
            st.insert(ss[i]);
        }

        string s1 = "assembler" , s2 = "operand" ;
        bool ok = true;


        for(int i =0;i<s1.length();i++)
        {
            if(!st.count(s1[i]))
            {
              //  cout << "No" << endl;
                ok = false;
            }
        }

        for(int i =0;i<s2.length();i++)
        {
            if(!st.count(s2[i]))
            {
              //  cout << "No" << endl;
                ok = false;
            }
        }

        if(ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }


   return 0;
}
