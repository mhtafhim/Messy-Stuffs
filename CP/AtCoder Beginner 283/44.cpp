
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

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
        cin>>s;
        //    long long zero=0;
        set<char> st;
        stack<char> stk;
        ll ind;
        ll loop = s.length();
        bool ok = true;
        ll braket =0;
        for(long long i =0; i<loop; i++)
        {


            //   cout << s[i] << endl;
            if(s[i] != '(' && s[i] != ')' && st.count(s[i]))
            {
                cout << "No" << endl;
                break;
            }
            else if(s[i] == ')')
            {

                ind = i-1;
                while(stk.top()!='(')
                {


                    st.erase(s[ind]);
                    stk.pop();
                    ind--;
                }
                stk.pop();

            }
            else if((!st.count(s[i])))
            {
                stk.push(s[i]);
                if(s[i] != '(' && s[i] != ')' )
                {
                    st.insert(s[i]);
                }
            }


        }

        if(stk.empty())
        {
            cout << "Yes" << endl;
        }







    }


    return 0;
}
