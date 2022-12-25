#include <bits/stdc++.h>
#define run ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long ll;

int main()
{
    run

    int t;
    t=1;
    cin >> t;
    while(t--)
    {
        ll n,m,k;
        cin >>n>>m>>k;
        vector<int> v(m);

        for(int i=0; i<m; i++)
        {
            cin >> v[i];
        }

        ll segment = (n+k-1)/k;
        ll seg = n/k;
        ll rem = n%k;
        ll counter1 =0;
        bool flag = false;

        for(int i=0; i<m; i++)
        {
            if(v[i]>segment)
            {
                cout << "NO" << endl;
                flag = true;
                break;
            }
            if(v[i]>seg)
            {
                counter1++;
                if(counter1>rem)
                {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout << "Yes" << endl;
        }



    }


    return 0;
}

