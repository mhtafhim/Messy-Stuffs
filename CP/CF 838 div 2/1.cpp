#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    typedef long long int lli;


    int t;
    t=1;
    cin >> t;
    while(t--)
    {
        lli n;
        cin>> n;

        lli countOdd=0;
        lli minOperation = 999999999;

        vector<lli> v(n);
        lli temp;
        lli operation =0;
        for(int i =0; i<n; i++)
        {
            operation =0;

            cin >> temp;
            if(temp%2!=0)
            {
                countOdd++;

            }

            if(temp%2==0)
            {
                while(temp%2==0)
                {
                    temp/=2;
                    operation++;
                }
            }
            else
            {
                while(temp%2!=0)
                {
                    temp/=2;
                    operation++;
                }
            }

            if(minOperation>operation)
                minOperation = operation;


        }

        if(countOdd%2==0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << minOperation << endl;
        }




    }


    return 0;
}
