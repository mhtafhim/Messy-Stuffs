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
       char temp;
       char m=0;
       for(int i =0;i<n;i++)
       {
         cin >> temp;
         if(m < temp)
            m = temp;
       }
       cout << (m - 'a')+1 << endl;

    }


   return 0;
}
