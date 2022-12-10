

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
        long long n;
        cin >> n;
        long long arr[n];
        long long smallest = 999999999999999;
        long long counter=0;
        bool flag= true;
        for(long long i =0; i < n; i++)
        {
            cin >>arr[i];

             if(smallest==arr[i])
                counter++;


            if(smallest>arr[i])
            {
                smallest = arr[i];
                counter = 1;
            }


            if(arr[i]%smallest!=0)
            {
                flag = false;
            }
        }

     //   cout << counter << " "<< smallest <<  " " << flag << endl;

        if(flag)
            cout << n-counter << endl;
        else
            cout << n << endl;

    }


    return 0;
}




