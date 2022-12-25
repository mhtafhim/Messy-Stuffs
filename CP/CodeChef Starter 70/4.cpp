
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
        char arr[n],arr2[n];
        int count1 =0;
        int count2 =0;

        for(int  i =0; i<n; i++)
        {
            cin >> arr[i];
            if(arr[i]=='1')
                count1++;
            //    cout << "bal 1"<< endl;
        }

        for(int  i =0; i<n; i++)
        {
            cin >> arr2[i];
            if(arr2[i]=='1')
                count2++;
             //   cout << "bal 2 " << endl;
        }

        if(count1==count2)
            cout << "YES"<<endl;
        else
            cout << "NO" << endl;


    }


    return 0;
}

