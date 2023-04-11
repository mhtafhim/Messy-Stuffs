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

    	int n,x,i;
    	cin >> n>> x;
    	char str[n+2];
    	cin >> str;

    	for(i =0;i<n;i++)
    	{
    		if((str[i]-'0')<x)
    		{
    			break;
    		}
    		
    	}

    	char temp=str[i];
    	str[i]=x+'0';

    	for(int j=i+1;j<=n;j++)
    	{
    		char temp2 = str[j];
    		str[j] = temp;
    		temp = temp2;
    	}

    	str[n+1] = '\0';

    	cout << str << endl;



    }


    return 0;
}
