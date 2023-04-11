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
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
    	lli x;
    	cin >> x;

    	if(x<10)
    		cout << x << endl;
    	else
    	{


    	std::string str = std::to_string(x);

    	int sz = str.length();
    	int ans = 0;
    	ans=(sz-1)*9;
    	
    	if(str[0]<=str[1])
    	{
    		ans+= str[0]-'0';
    	}
    	else 
    	{
    		ans+= str[0]-'0';
    		ans--;
    	}

    	

    	cout << ans << endl;


    	}

    }


    return 0;
}
