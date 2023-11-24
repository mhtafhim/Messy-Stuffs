#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

void solve(int cs)
{
    int n;
    cin >> n;

    vector<ll> va(n), ca(n), vb(n), cb(n);

    vector<vector<ll>> q(2*n + 2);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> va[i];
    }


     for(int i = 0 ; i < n ; i++)
    {
        cin >> ca[i];
    }

     for(int i = 0 ; i < n ; i++)
    {
        cin >> vb[i];
    }


     for(int i = 0 ; i < n ; i++)
    {
        cin >> cb[i];
    }


   for (int i = 0; i < n; i++)
    {
      //  q[ca[i]].push_back(va[i]);
        q[cb[i]].push_back(vb[i]);
    }


    for (int i = 0; i < n; i++)
    {
    	if(q[i].size() > 0)
        sort(q[i].begin(), q[i].end());
    }

    bool ok = true;

  	if(q[ca[0]].size() > 0)
  	{
    if (q[ca[0]][0] < va[0])
    {
    	swap(va[0] , q[ca[0]][0]);
       // va[0] = q[ca[0]][0];
    }
  	}


  	 for (int i = 1; i < n; i++)
    {
        int lb = -1;

        if (q[ca[i]].size() > 0)
        {
        	sort(q[ca[i]].begin(), q[ca[i]].end());
            lb = lower_bound(q[ca[i]].begin(), q[ca[i]].end(), va[i - 1]) - q[ca[i]].begin();
          //  cout << va[i - 1] << "   ";
           //  cout << i << " " <<lb << " ";
           //  cout << va[i] << " " << q[ca[i]][lb]  << endl;

            if (va[i] > q[ca[i]][lb] && (lb < q[ca[i]].size() ) && (lb >= 0))
            {
              //  cout << "dukse" << endl;
                swap(va[i] ,q[ca[i]][lb]);
            }
            else if((va[i] < va[i - 1])  && (q[ca[i]][lb] > va[i - 1] ) && (lb < q[ca[i]].size() ) && (lb >= 0) )
            {
             //     cout << "dukse" << endl;
                swap(va[i] ,q[ca[i]][lb]);
            }
        }

        if (va[i] < va[i - 1])
        {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}