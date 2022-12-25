
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
        cin >> n;
        vector<int> v(n);
        vector<int> cnt(n,0);
        map<int,int> mp;
        map<int,int>:: iterator itr;
        int index=1;
        int maximum = -999999;

        for(int i =0; i<n; i++)
        {

            cin>>  v[i];
            cnt[v[i]]++;
            if(mp.count(v[i])==0)
            {
                mp[v[i]]=index;
                index++;
            }
            if(maximum < v[i])
                maximum = v[i];

        }

        for(int i =0; i<n; i++)
        {

            cout << cnt[i] << " ";
        }
        cout << endl;



        if(maximum > n)
        {
            cout << -1 << endl;
            continue;
        }

        int flag = 0;


        for(int i =0; i<n; i++)
        {
            if(cnt[v[i]]> v[i])
            {
                cout << flag <<  "  " << cnt[v[i]] << endl;
                if(flag<=cnt[v[i]])
                {
                    cout << mp[v[i]] << " ";
                    flag++;
                }
                else
                {
                    itr = mp.find(v[i]);
                    if (itr != mp.end())
                        itr->second = index;

                    index++;
                    flag = 1;
                    cout << mp[v[i]] << " ";

                }
            }
            else
            {
                cout << mp[v[i]] << " ";
            }

        }

        cout << endl;



    }


    return 0;
}



