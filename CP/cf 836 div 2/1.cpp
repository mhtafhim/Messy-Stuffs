
#include <bits/stdc++.h>

using namespace std;

bool check(vector<char> v)
{
    int sz = v.size();
    for(int i =0; i<sz/2; i++)
    {
        if(v[i]!=v[sz-1-i])
            return false;
    }
    return true;
}


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
        cin >> s;
        vector<char> v;

        for(int i =0; i<s.length(); i++)
        {
            v.push_back(s[i]);
            v.push_back(s[i]);
        }

    //    sort(v.begin(),v.end());


        do
        {
            if(check(v))
            {
               break;


            }

        }
        while ( next_permutation(v.begin(),v.end()) );


        int sz = v.size();
        for(int i =0; i<sz; i++)
        {
            cout << v[i] ;
        }
        cout << endl;


    }


    return 0;
}
