
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

        long long n,ans;
        cin >>n;
        vector<int> v;

        for(int i =0;i<n;i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());

     //   bool flag1 = false,flag2 = false;

        long long counter =0,counter2 =0;
        long long i =0,j = n-1;

        if(v[0]==v[n-1])
        {
            cout << (n-1)*n << endl;
             v.clear();
            continue;
        }

        while(v[0]==v[i])
        {
             counter++;
             i++;
        }


        while(v[n-1]==v[j])
        {
             counter2++;
             j--;
        }

        ans = 2*counter*counter2;
        cout <<  ans << endl;


        v.clear();

    }


   return 0;
}
