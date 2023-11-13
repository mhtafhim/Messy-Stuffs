#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


bool ok(string one,string two)
{

    
    string nw = one + two;
 

    int sz = nw.size();

    if(sz&1) return false;

    int half = sz/2;
    int sum = 0 ,sum2 = 0;
    for(int i =0 ; i < half ; i ++)
    {
        sum += nw[i];
    }

    for(int i = half ; i < sz ; i ++)
    {
        sum2 += nw[i];
    }

    if(sum == sum2) return true;
    else return false;

}


void solve(int cs){
        int n;

        cin >> n ;


        vector<string> vec(n),even,odd;
        ll cnt = 0 ;

        for(int i = 0 ; i < n ; i ++)
        {
            cin >> vec[i];
            if(vec[i].size()%2==0)
            {
                even.push_back(vec[i]);
            }
            else
            {
                odd.push_back(vec[i]);
            }
        }

        int esz = even.size();
        int osz = odd.size();

        for(int i = 0 ; i < esz ; i ++)
        {
            for(int j = 0 ; j < esz ; j ++)
            {
                if(ok(even[i],even[j])) cnt++;
            }
        }

        for(int i = 0 ; i < osz ; i ++)
        {
            for(int j = 0 ; j < osz ; j ++)
            {
                if(ok(odd[i],odd[j])) cnt++;
            }
        }

        cout << cnt << endl;

        



}

int main(){
    fast;
    int t=1;
 //   cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    } 
    return 0;
}
