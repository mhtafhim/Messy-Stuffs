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
       cin>>n;
       vector<long long>participate(n);
       bool flag = false;
       long long maximum = INT_MIN;
       long long secondMax = INT_MIN;
       for(long long i =0;i<n;i++)
       {
         cin >> participate[i];
         if(maximum<participate[i])
         {
            secondMax = maximum;
            maximum = participate[i];
         }
         else if(secondMax < participate[i] && participate[i] != maximum)
         {
            secondMax = participate[i];
         }
         if(participate[i-1]!=participate[i] && i>0)
         {
            flag = true;
         }
         cout << maximum << " " << secondMax <<" "<< flag << endl;

       }

       for(long long i=0;i<n;i++)
       {
         if(participate[i]== maximum && flag == false)
         {
            cout << 0 << " ";
            continue;
         }
         if(participate[i]!=maximum)
         {
            cout << participate[i] - maximum<< " ";
         }
         else
         {
            cout << participate[i] - secondMax << " ";
         }
       }
   //    cout << endl;

    }


   return 0;
}
