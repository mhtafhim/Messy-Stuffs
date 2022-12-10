
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
    cin >> t;
    while(t--)
    {
        string s;
        int len;
        cin >> len;
        cin>> s;
        bool flag = false;

        for(int i =0; i<len/2; i++)
        {
            if(s[i] != s[len/2 +i])
            {
               // cout << s[i] << " " << s[len/2 +i] << endl;
                flag = true;
            }
        }
        if(flag == false)
            cout << "YES" << endl;
        else
            cout << "NO"<< endl;

    }


    return 0;
}

