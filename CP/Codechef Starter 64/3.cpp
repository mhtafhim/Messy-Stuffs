

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
        cin >> n;

        int maximum = -10000000;

        for(int i =0;i<n;i++)
        {
            int temp;
            cin >> temp;
            if(temp >maximum)
                maximum = temp;
        }

        cout << maximum << endl;

    }


    return 0;
}


