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
        int m,s;
        cin >>m>>s;
        bool arr[1000] = {false};
        int maximum=-99999999;
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            int temp;
            cin>>temp;
            arr[temp] = true;
            if(maximum <temp)
                maximum = temp;
        }

        int i = 1;

        for(int i = 1;i<maximum;i++)
        {
            if(arr[i]==false)
                ans = ans + i;
        }
        i = maximum+1;

      //  cout << " ans1 = " << ans << endl;

         if(ans == s){
             cout << "Yes" << endl;
             continue;
        }
        else if(ans < s)
        {
            while(ans < s)
            {
                ans = ans + i;
                i++;
           //      cout << " ans2 = " << ans << endl;
                if(ans == s)
                {
                    cout << "Yes" << endl;
                    continue;
                }
                else if(ans > s)
                {
                    cout << "No" << endl;
                    continue;
                }
            }
        }
        else
            cout << "No" << endl;







    }


   return 0;
}

