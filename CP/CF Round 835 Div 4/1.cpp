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
       int a[3];
       int max= -99999,min=99999999;
       for(int i=0;i<3;i++)
       {
         cin>>a[i];
         if(max<a[i])
            max = a[i];
         if(min>a[i])
            min=a[i];


       }
       int ans = (a[0]+a[1]+a[2])-(min+max);
         cout << ans << endl;


    }


   return 0;
}
