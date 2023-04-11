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

    local();

    lli t;
    t=1;
  //  cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
    	int x;
    	cin >> x;
    	for(int i =0;i<5;i++)
    		cout << x+i << endl;


    }


    return 0;
}
