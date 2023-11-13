#include <iostream>
#include <vector>

using namespace std;
#define ll long long int

int knapsack(ll n, ll W, vector<ll> wt, vector<ll> val)
{
    vector<vector<ll>> V(n + 1, vector<ll>(W + 1));

    for (ll i = 0; i <= n; i++)
    {
        for (ll w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                V[i][w] = 0;
            else if (wt[i - 1] <= w)
                V[i][w] = max(val[i - 1] + V[i - 1][w - wt[i - 1]], V[i - 1][w]);
            else
                V[i][w] = V[i - 1][w];
        }
    }

    return V[n][W];
}

int main()
{
    ll n = 5, W;
    cin >> n;
    vector<ll> val;
    vector<ll> wt;
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i ++)
    {
        ll tmp;
        cin >> tmp;
        sum += tmp;
        val.push_back(tmp);
        wt.push_back(tmp);
    }
    
    W = sum/2;
    

    ll half = knapsack(n, W, wt, val);
    cout <<abs((sum - half) - half) << endl;

    return 0;
}

