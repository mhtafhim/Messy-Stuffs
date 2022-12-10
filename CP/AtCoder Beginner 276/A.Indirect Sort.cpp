#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool ans = false ;
     //   long long minimum = 100000000000000000000;
        int first;
        int temp;
        cin >> first;
        for(int i =1;i<n;i++)
        {
            cin >> temp;
            if(first > temp )
            {
                ans = true;
            }
        }
        if(ans)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }


   return 0;
}

