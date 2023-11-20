#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


int maxSubArraySum(int arr[], int size) {
    int max_sum = INT_MIN; // Initialize max_sum to negative infinity
    int current_sum = 0;

    for (int i = 0; i < size; ++i) {
        if((i!=0) && !((arr[i]&1) ^ (arr[i-1])&1) )
        {
            current_sum = arr[i];
        }
        else
        {
            current_sum = std::max(arr[i], current_sum + arr[i]);
        }
   //   current_sum = std::max(arr[i], current_sum + arr[i]);
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}


void solve(int cs){
    int n;
    cin >> n; 

    int vec[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> vec[i];
    }

    cout << maxSubArraySum(vec,n) << endl;;
    
}

int main(){
    fast;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    } 
    return 0;
}
