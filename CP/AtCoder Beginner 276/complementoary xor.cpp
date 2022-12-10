#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<char> v;
        char temp;
        bool flag1=true,flag2 = true;
        for(int i =0;i<n;i++)
        {
            cin>>temp;
            v.push_back(temp);

        }

         for(int i =0;i<n;i++)
        {
            cin>>temp;
            if(v[i]==temp)
            {

            }
            else{
                flag1 = false;
            }
            if(v[i]!=temp)
            {

            }
            else{
                flag2= false;
            }


        }
        if(flag1 || flag2)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }


    }


   return 0;
}

