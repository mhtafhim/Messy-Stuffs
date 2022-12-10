
#include <bits/stdc++.h>

using namespace std;


int distict(vector<int> v,int l,int r)
{
    bool arr[10] = {false};
    for(int i = l ; i<=r ; i++)
    {
        arr[v[i]%10] = true ;
    }
    int x=0;
    for(int i =1;i<10;i++)
    {
     //   cout << arr[i] << endl;
        if(arr[i] == true)
            x++;

    }


    return x;
}

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
        int dis,L,R;
        cin>>n;
        vector<int> v(n+1);

        for(int i=1 ; i<=n ; i++)
        {
            cin >> v[i];
        }
        int maximum = -99999999;


        for(int r = 1; r<= n ; r++)
        {
            for(int l = 1 ; l<=r ;l++ )
            {
             //  cout << l << " " << r << endl;
               int distic = distict(v,l,r);
               dis = (r- l - distic);
        //    cout << dis << " " << distic<< " " << l << " " << r  << endl;
                if(dis > maximum)
                {
                    maximum = dis;
                    L = l ;
                    R = r;


                }
            }
        }

        cout << L << " " << R << endl;




    }


   return 0;
}
