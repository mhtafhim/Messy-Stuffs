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
typedef long long int ll;
const ll mod=1000000007;

int main()
{
    fast

    ll t;
    t=1;
    cin >> t;
    for(int tc =1;tc<=t;tc++)
    {
        int n;
        cin >> n;
        int arr[n-5];
        vector<int> vec(n+5);
        for(int i =0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            vec[tmp+1]--;
            vec[1]++;
            arr[i]= tmp;

        }
        bool ok = true;
        vector<int>sum(n+5);

        for(int i =1;i<=n;i++)
        {
            sum[i] = sum[i-1]+ vec[i];


        }
         for(int i =1;i<=n;i++)
        {
        //     cout << sum[i] << " "<< arr[i-1] << endl;
            if(sum[i]!=arr[i-1]){ok = false;break;}

        }



        (ok?cout<< "YES" : cout <<"NO");
        cout << endl;


    }


   return 0;
}

