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

        lli x,y;
        cin >>x>>y;

        string s,ss,sss;
        cin >> s;

        lli len = s.length();

        lli a;

        a = y % x;

    //    cout << a << endl;

        for(int i =0;i<a;i++)
        {
            char temp = s[i];
        //    cout << "hi" << endl;
            sss.push_back(temp);
        }

       // sss = ss;
    //   cout << s << endl;
     //   cout << sss << endl;
   //     reverse(sss.begin(),sss.end());

        bool ok = true;
        int index = 0;
        int cnt = 0;

        for(int i = 0;i<len;i++)
        {

            if(cnt >= a)
            {
                reverse(sss.begin(),sss.end());
                index =0;
                cnt = 0;
            }
        //    cout << s[i] << " ->>>  " << sss[index] << endl;
            if(s[i]!=sss[index])
            {
              //  cout << s[i] << " fuck " << sss[index] << endl;
                ok = false;
               // break;
            }
            index++;
            cnt++;
        //    cout << index << endl;
        }

   //     cout << index  << " baal " << y<< endl;
        if(ok && index == a)cout << "Yes" << endl;
        else cout << "No" << endl;





    }


   return 0;
}
