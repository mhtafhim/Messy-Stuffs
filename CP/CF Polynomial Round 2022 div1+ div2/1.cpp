
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
        vector<char> v(n);
        for(int i =0;i<n;i++)
        {
            cin>>v[i];
        }

        int ans = (v[0] - 48);

        for(int i =1;i<n;i++)
        {
        //    cout << ans << "  " << v[i] << endl;
            if(ans==0 && (v[i]=='0' || v[i]=='1'))
            {
                cout << "+" ;
                ans +=(v[i] - 48);
            }
            else if(ans ==1 && v[i]=='0')
            {
                cout << "+" ;
                ans +=(v[i] - 48);
            }
            else if(ans ==1 && v[i]=='1')
            {
                cout << "-" ;
                ans -=(v[i] - 48);
            }
            else{
                cout << "fuck u ";
            }
        }

        cout << endl;

    }


   return 0;
}
