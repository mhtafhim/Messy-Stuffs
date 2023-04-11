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


void local()
{
    fast
#ifndef ONLINE_JUDGE
    freopen("inputf.txt","r", stdin);
    freopen("outputf.txt","w", stdout);

// ONLINE_JUDGE
#endif
}


int main()
{

 //   local();

    lli t;
    t=1;
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
    	int n;
    	cin >> n;
    	vector<int>vec;
    	for(int i =0;i<n-1;i++)
    	{
    	    int temp;
    	    cin >> temp;
    		vec.pb(temp);
    	}

    	if(vec[n-2]==0 || vec[n-2]<vec[n-3])
    		vec.pb(0);
    	else
    	{
    		vec.insert(vec.begin()+1,0);
    	}

    	for(auto it:vec)
    	{
    		cout << it << " ";
    	}

    	cout << endl;
    }


    return 0;
}
