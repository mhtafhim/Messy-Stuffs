
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin >>t;

    while(t--)
    {

        long long int n,m;
         long long int ans=0;


        cin >> n>>m;

        vector<long long int> arr;

        for(long long int i =0; i<m; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        if(n>=m)
        {
            for(long long int i = 0; i<m ; i++)
            {
                ans = ans + arr[i];
            }

            cout << ans<< endl;
            continue;
        }


        sort(arr.begin(),arr.end());





        for(long long int i = 0; i<n ; i++)
        {
            ans = ans + arr[m-1-i];
         //   cout << arr[m-1-i] << "   ";
        }

        cout << ans << endl;
    }

    return 0;
}
