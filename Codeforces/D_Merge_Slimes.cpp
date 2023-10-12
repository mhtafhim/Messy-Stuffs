//competitive programming c++ template
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define fill(a,b) memset(a,b,sizeof(a))
#define sp(x,y) fixed<<setprecision(y)<<x<<" "
#define endl "\n"
#define debug(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<" "<<y<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define debug4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define debugarr(arr) for(auto x: arr) cout<<x<<" "; cout<<endl;
#define debugarr2(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
#define debugarr3(arr,n) for(int i=1;i<=n;i++) cout<<arr[i]<<" "; cout<<endl;
#define debugvec(vec) for(auto x: vec) cout<<x<<" "; cout<<endl;
#define debugvec2(vec,n) for(int i=0;i<n;i++) cout<<vec[i]<<" "; cout<<endl;
#define debugvec3(vec,n) for(int i=1;i<=n;i++) cout<<vec[i]<<" "; cout<<endl;

//define vector input
#define vcin(vec,n) for(int i=0;i<n;i++) cin>>vec[i];
//define vector input using insert function
#define vcin2(vec,n) for(int i=0;i<n;i++){ int x; cin>>x; vec.pb(x);}



void solve(int cs)
{

    int idx = 1e9;
    int inff = 1e5;
    vector<int> arr(idx);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i =0; i < n; i ++ )
    {
        int x,y;
        cin >> x >> y;
        arr[x] = y ;
       
    }
    

    for(int i = 0; i<inff ; i++)
    {
        if( arr[i]&1 )
        {
            int cal = arr[i]/2;
            arr[i] = 1;
            int tmp = i*2;
            arr[tmp] += cal;
        }
        else
        {

            int cal = arr[i]/2;
            int tmp = i*2;
            arr[tmp] += cal;
            arr[i] = 0;
        }
    }

    for(int i =0 ; i< idx; i++)
    {
        cnt +=arr[i];
    }

    cout << cnt << endl;



}

int main()
{
    fast;
    int t=1;
//   cin>>t;
    for(int i=1; i<=t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
