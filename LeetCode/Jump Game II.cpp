#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int jump(vector<int> &nums)
{

    int sz = nums.size();

    int cnt = 0, i = 0, idx = 0;
    int track = 0;

    while (i < sz-1)
    {

        cnt++;
        int mx = nums[i + 1];

    //    cout << i << endl;
        for (int j = i + 1; (j <= (i + nums[i])); j++)
        {
          //  cout << (j + nums[j]) << " ";
            if(j>=sz-1)
            {
                idx = j;
                break;
            }
            else if (((j < sz)) and (mx < (j + nums[j])))
            {
                mx = (j + nums[j]);
                idx = j;
                if(j>=sz-1)
                {
                    idx = j;
                    break;
                }
            }
           
        }

     //   cout << endl << endl;

        i = idx;
    }

    return cnt;
}

void solve(int cs)
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];


    cout << jump(nums) << endl;
}

int main()
{
    fast;
    int t = 1;
    //  cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
