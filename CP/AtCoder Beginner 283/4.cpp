

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
  //  cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
    //    long long zero=0;
        set<char> st;
        stack<char> stac;
        ll ind;
        ll loop = s.length();
        bool ok = true;
        ll braket =0;
        for(long long i =0;i<loop;i++)
        {


            cout << s[i] << endl;
           if(s[i] != '(' && s[i] != ')' && st.count(s[i]))
           {
               cout << "loop 1" << endl;
               cout << "No" << endl;
          //     ok = false;
               break;
           }
           else if(s[i] != '(' && s[i] != ')' && (!st.count(s[i])))
           {
               cout << "loop 2" << endl;
             //  cout << "ok " << endl;
               st.insert(s[i]);
           }
           else if(s[i] == ')')
           {
               cout << "loop 3" << endl;
               ind = i-1;
               while(ind > 0)
               {
                  // cout << "chudse "  << s[ind] << endl;
                  if(s[ind]=='(' )
                  {
                       cout << "deleting " << s[ind] << endl;
                      st.erase(s[ind]);
                      break;
                  }
                    if(st.count(s[ind]))
                    {
                        cout << "deleting " << s[ind] << endl;
                        st.erase(s[ind]);
                      //  break;
                    }
                    ind--;
               }

           }

        }

        if(st.empty())
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;






    }


   return 0;
}

