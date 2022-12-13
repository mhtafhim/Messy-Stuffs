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
        int n;
        cin>>n;
        string s;
        cin >> s;
        long long cnt = 0;
        int index1,index2;
        bool flag = false;
        for(int i =0; i<n; i++)
        {
            cnt = 0;
            index1 = i;
            for(int j = i+1,index2 = i+1; j<n ; j++)
            {
                index1 = i;
                if(s[index1]==s[j] )
                {
                    while(1)
                    {
                        cnt++;
                        if(s[++index1]==s[++j] && index1 < index2)
                        {
                            cnt++;
                            cout << index1 << " " << j << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if(cnt>1)
                {

                    flag = true;
                    break;
                }

            }
            if(flag)
            {
                break;
            }


        }
        if(flag)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            cout << "NO" << endl;

        }


    }


    return 0;
}

