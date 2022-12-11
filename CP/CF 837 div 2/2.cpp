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
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n>>m;
        vector<int> vec[n+1];
        bool genjam[n+1] = {false};
        ll ans = n;
        for(int i =0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            if(v>u)
            {
                vec[u].push_back(v);
                genjam[v] = true;
            }
            else
            {
                vec[v].push_back(u);
                genjam[u] = true;
            }


        }

        for(int j =1; j<n; j++)
        {
            sort(vec[j].begin(),vec[j].end());
            if(vec[j].size()==0)
            {
                cout << "check 1" << endl;
                int temp = 1;
                int ti = j+1;
                while(1)
                {
                    if(genjam[j]==false)
                    {
                        temp++;
                        ti++;
                        cout << "check 2" << endl;
                    }
                    else
                        break;


                }
                ans = ans + (pow(2,temp)-temp-1);
                continue;
            }
            int temp = vec[j][0] - j ;
            ans = ans + (pow(2,temp)-temp-1);

        }

        cout << ans << endl;


    }


    return 0;
}

