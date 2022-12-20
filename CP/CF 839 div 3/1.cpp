#include<bits/stdc++.h>

using namespace std;



int main()
{

    int t;
    cin>>t;

    while(t--)
    {

        char a[3];

        cin >> a[0] >> a[1] >> a[2] ;

        int res = a[0] + a[2] - 48 - 48;


        cout << res << endl;


    }

    return 0;
}
