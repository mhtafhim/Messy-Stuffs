
#include<bits/stdc++.h>

using namespace std;



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        vector<int>v(27,0);
        int n;
        cin>>n;
        bool flag=false;
        for(int i =0; i<n; i++)
        {
            char temp;
            cin >> temp;

            v[temp-97]++;
        }

        for(int i =0; i<26; i++)
        {
          //  cout << v[i] << " " ;

            if(v[i]%2!=0)
            {
                flag = true;
            }


        }

        if(flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;



    }

    return 0;
}
