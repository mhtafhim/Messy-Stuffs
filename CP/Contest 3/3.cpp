#include <bits/stdc++.h>
using namespace std;


void solve(string st, int N)
{
    bool ans = true;

    stack<char> s;

    for (int i = 0; i < N; i++)

        if (st[i] == '(')
            s.push(st[i]);
        else
        {
            if (!s.empty())
            {

                char temp = s.top();

                s.pop();

                if (st[i] == ')' && temp != '(')
                {
                    ans = false;
                    break;
                }

            }

            else
            {
                ans = false;
                break;
            }
        }



    if (!s.empty())
        ans = false;
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}


int main()
{
    string s;
    cin>>s;
    int N = s.length();


    solve(s, N);
}
