
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    //  t=1;
    cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        bool flag = true;

        int len = s.length();

        if(len<2)
            if(s[0]!='Y' && s[0]!='e' && s[0]!='s' )
                flag =false;

        for(int i =0; i<len-1; i++)
        {
            if(s[0]=='Y' || s[0]=='e' || s[0]=='s' )
            {


                if(s[i]=='Y' && s[i+1]!='e')
                    flag = false;
                else if(s[i]=='e' && s[i+1]!='s')
                    flag = false;
                else if(s[i]=='s' && s[i+1]!='Y')
                    flag = false;
            }
            else
            {
                flag = false;
                break;
            }

        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;


    }


    return 0;
}
