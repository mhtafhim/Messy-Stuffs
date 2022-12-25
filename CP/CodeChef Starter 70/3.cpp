
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
        int n,x;
        cin>>n>>x;
        int freshness[n],cost[n];
        for(int  i =0;i<n;i++)
        {
            cin >> freshness[i];
        }

         for(int  i =0;i<n;i++)
        {
            cin >> cost[i];
        }

        int total=0;

         for(int  i =0;i<n;i++)
        {
            if(freshness[i]>=x)
            {
                total +=cost[i];
            }
        }

        cout << total << endl;



    }


   return 0;
}
