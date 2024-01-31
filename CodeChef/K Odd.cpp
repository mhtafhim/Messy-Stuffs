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

    ll n,k;
    cin >> n >> k;

    vector<int> v;

    if(k&1)
    {
        ll tmp = k/2;
        ll limit =(n+1)/2 - tmp;
        ll last=1,last2=2;
        int j = 1;
        for(int i = 0 ; i < limit ; i ++ , j++)
        {
            v.push_back(last);
            last +=2;
        }
        for(int i = 0 ; i < k ; i ++,j++)
        {
            if(i %2 ==0)
            {
                v.push_back(last2);
                last2+=2;
            }

            else
            {
                v.push_back(last);
                last+=2;
            }
        }

        for(; j <= n ; j++)
        {

            v.push_back(last2);
            last2+=2;
        }

    }
    else
    {

        ll tmp = k/2 - 1;
        ll limit =(n+1)/2 - tmp - 1;
        ll last=1,last2=2;
        int j = 1;
        for(int i = 0 ; i < limit ; i ++ , j++)
        {
            v.push_back(last);
            last +=2;
        }
        for(int i = 0 ; i < k -1 ; i ++,j++)
        {
            if(i %2 ==0)
            {
                v.push_back(last2);
                last2+=2;
            }

            else
            {
                v.push_back(last);
                last+=2;
            }
        }
      //  v.push_back(96);

        for(; j < n ; j++)
        {

            v.push_back(last2);
            last2+=2;
        }
        v.push_back(last);

    }

    for(auto x : v)cout << x << ' ';
    cout << endl;



}

int main()
{
    fast;
    int t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
