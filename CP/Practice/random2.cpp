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

int main()
{

    fast

    lli t,n,i,x,mx,mn,f,j,s,r,y,c,m,k,z;
    t=1;
    cin >> t;
    for(int tc =1; tc<=t; tc++)
    {
        map<string,string> mp;

        string s1,s2,s3 = "https://";
        cin >> n;

        for(int i =0; i<n; i++)
        {
            cin >> x;
            if(x==1)
            {
                cin >> s1>>s2;
                mp[s1] = s2;
            }
            else if (x==2)
            {
                cin >> s1;
                if(mp.count(s1))
                {
                    string temp = mp[s1];

                    string temp2;
                    z = temp.length();
                    while(z>=0)
                    {
                        temp2.push_back(temp[z]);
                        z--;
                        if(temp[z]=='/' && temp[z-1]=='/')
                            break;
                    }
                    reverse(temp2.begin(),temp2.end());
                    string temp3 = s3 + temp2;

                   cout << temp3<< endl;
                }
                else
                {
                    cout << "404! Not Found" << endl ;
                }
            }
        }


    }


    return 0;
}
