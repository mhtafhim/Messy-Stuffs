
#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int len = s.length();
    int ans=-1;

    for(int i = 0;i<len;i++)
    {
        if(s[i]=='a')
            ans = i+1;

    }

    cout << ans << endl;

   return 0;
}

