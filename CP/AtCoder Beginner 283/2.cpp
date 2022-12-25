

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
  //  cin >> t;
    while(t--)
    {
        ll n,q,q1,q2,q3;
        cin >> n;
        vector<ll> v(n+1);
        for(int i =1 ;i <= n ; i++)
        {
            cin >> v[i];
        }

        cin >> q;

        while(q--)
        {

            cin >>q1;
            if(q1==2)
            {
           //     cout << "baaal" << endl;
                cin >> q2;
                cout << v[q2] << endl;
            }
            else if(q1==1)
            {
            //    cout << "baaal2" << endl;
                cin >>q2>>q3;
                v[q2] = q3;
            }

         //    cout << q1<<" " << q2 << " " << q3 << " " << endl;

        }




    }


   return 0;
}

