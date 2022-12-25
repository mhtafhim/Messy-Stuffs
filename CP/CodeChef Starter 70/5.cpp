
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
        bool flag =false;
        bool ans = false;

        for(int  i =0; i<n; i++)
        {
            cin >> arr[i];
            if(arr[i]=='1' && flag == false)
            {
                count1=i;
                flag = true;
            }
            else if(arr[i]=='1')
            {
                count2 = i-count1;
              //  cout << count2 << endl;
                count1 = i;
                if(count2%2!=0)
                {
                    ans = true;
                }

            }

        }
        if(n==2)
        {
            cout << 1 << endl;
        }
        else if(ans)
            cout << 1 << endl;
        else
            cout << 2 << endl;






    }


    return 0;
}


