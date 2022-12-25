

#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
  //  cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        long long zero=0;

        for(long long i =0;i<s.length();i++)
        {
            if(s[i]=='0' && s[i+1]=='0')
            {
                zero++;
                i++;
            }
            if(s[i]== '0' && s[i]!= '0')
            {
                i++;
            }

        }

        long long ans = s.length() - zero;
        cout << ans << endl;


    }


   return 0;
}
