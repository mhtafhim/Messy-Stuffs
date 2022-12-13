
#include <bits/stdc++.h>

using namespace std;

void solve(string s,int n)
{
    int cnt =0,in1,in2,maximum;

    for(int i =0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            in1 = i;
            in2 = j;
            maximum = j;
            cnt=0;

            if(s[i]==s[j])
            {
                while(1)
                {
                    cnt++;

                    if(s[++in1]==s[++in2])
                    {
                        if(in1>=maximum || in2 >= n)
                            break;
                  //      cout << in1 << " " << in2 << " " << maximum << endl;
                        cnt++;

                    }
                    else
                    {
                        break;
                    }


                }
            }
            if(cnt>2)
            {
                cout << "YES" << endl;
                return;

            }
        }
    }
    cout << "NO" << endl;
    return;

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
        int n;
        cin>>n;
        string s;
        cin >> s;

        solve(s,n);


    }

    return 0;
}

