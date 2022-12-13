
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t;
    t=1;
   cin >> t;
    while(t--)
    {
        long long x;
        cin>>x;

        if(x<10)
        {
            cout << x << endl;
        }
        else if(x>9 && x < 100)
        {
            x = x/10;
            cout << x+9 << endl;
        }
        else if(x>99 && x < 1000)
        {
            x = x/100;
            cout << x + 18 << endl;
        }
        else if(x>999 && x < 10000)
        {
            x = x/1000;
            cout << x + 18 +9 << endl;
        }
        else if(x>9999 && x < 100000)
        {
            x = x/10000;
            cout << x + 18 + 9 + 9 << endl;
        }
        else if(x>99999 && x < 1000000)
        {
            x = x/100000;
            cout << x + 18 + 9 + 9 +9 << endl;
        }
        else if(x>999999 && x < 10000000)
        {
            x = x/1000000;
            cout << x + 18 + 9  + 9 +9 +9 << endl;
        }

    }


    return 0;
}
