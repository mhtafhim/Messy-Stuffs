#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define memset(v,x) memset((v),x,(sizeof(v)))
using namespace std;
typedef long long int lli;
const lli mod=1000000007;

int main()
{

    fast

    lli t;
    t=1;
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
        lli n ;
        cin >> n;
        //   vector<bool> vec(n,false);
        vector<int> ans;
        int temp;
        int sum=0;

        vector<int>vec(n+1,0);



        for(int i =1; i<=n; i++)
        {
            //  sum = 0;
            for(int j=1; j<n; j++)
            {
                cin >> temp;
                vec[temp]+=j;
            }
        }

        priority_queue<pair<int,int>> pq;

        for(int i=1;i<=n;i++)
        {
            pq.push({((-1)*vec[i]),i});
        }


        pair<int,int> pr;
        while(!pq.empty())
        {
            pr = pq.top();
            pq.pop();
            cout << pr.second << " ";
        }
        cout << endl;




    }



    return 0;
}


