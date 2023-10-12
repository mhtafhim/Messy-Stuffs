#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

double distance(double ax,double ay,double bx,double by)
{
   
    double dis = sqrt(pow((ax-bx),2)+pow((ay-by),2));

    return dis;

}


void solve(int cs){
   
     double px,py,ax,ay,bx,by;
    cin >> px >> py;
    cin >> ax >> ay;
    cin >> bx >> by;


    double disOP , disAB , disOA , disOB , disPA , disPB,ans = -1;
    disOP = distance(0,0,px,py);
    disOA = distance(0,0,ax,ay);
    disOB = distance(0,0,bx,by);
    disPA = distance(px,py,ax,ay);
    disPB = distance(px,py,bx,by);
    disAB = distance(ax,ay,bx,by);
    

  //  double tmp1 = min(disOA,disOB), tmp2 = min(disPA,disPB);

    if(disOA <= disOB)
    {
        
        if(disPA <= disPB)
        {
            ans = max(disOA,disPA);
        }
        else
        {
            ans = max(disAB/2,max(disPB,disOA));
        }
    }
    else
    {
        if(disPA < disPB)
        {
            ans = max(disAB/2,max(disPA,disOB));
        }
        else
        {
            ans = max(disOB,disPB);
        }
    }

    cout << ans << endl;
    
}

int main(){
    cout << fixed << setprecision(10) ;
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
