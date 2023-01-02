#include <bits/stdc++.h>
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t,n,i,x,mx,mn,f,j,s,r,y,c,m,k,z;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=n;
        y=n+1;
        z=2*n+1;
        if(x%3==0)x/=3;
        else if(y%3==0)y/=3;
        else z/=3;
        s=x;
        s*=y;
        s%=mod;
        s*=z;
        s-=n*(n+1)/2;
        s%=mod;
        s+=mod;
        s%=mod;
        s*=(lli)2022;
        s%=mod;
        cout<<s<<endl;
    }
}

