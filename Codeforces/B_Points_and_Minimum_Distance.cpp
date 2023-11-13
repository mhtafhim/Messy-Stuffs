#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


void solve(int cs){
    int n;
    cin >> n ;

    vector<int> vec(2*n);

    for(int i = 0 ; i< 2*n; i ++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(),vec.end());

    vector<int>first,sec;

    for(int i = 0 ; i < n ; i ++)
    {
        first.push_back(vec[i]);
    }

    for(int i = n ; i < 2*n ; i ++)
    {
        sec.push_back(vec[i]);
    }

    int sum = 0;
    for(int i = 1 ; i<n ; i ++)
    {
        sum += abs(first[i-1] - first[i]);
        sum += abs(sec[i-1] - sec[i]);
    }

    cout << sum << endl;

     for(int i = 0 ; i < n ; i ++)
    {
        cout << first[i] << " " << sec[i] << endl;
    }


    
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
