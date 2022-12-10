

#include <bits/stdc++.h>

using namespace std;

float sumOfAP(float a, float d, float n)
{
    float sum = (n / 2) * (2 * a + (n - 1) * d);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int N,x,y;
        cin >> N>>x>>y;
        int ans = 0;
        int total = (N*(N+1))/2;
        float term2 = N/x;
        float term3 = N/y;
        int total2;
        int total3;


        if(x%y!=0 && y%x!=0)
        {

            if(term2==1)
                total2 = x;
            else
                total2 = sumOfAP((float)x,(float)x,(float)term2);

            if(term3 == 1)
                total3 = y;
            else
                total3 = sumOfAP((float)y,(float)y,(float)term3);
            ans = total - total2 - total3;
           // cout << total << " " << total2 <<" " << total3 << " "<<ans << endl;

           cout <<ans << endl;
        }
        else if(x==y)
        {
            if(term2==1)
                total2 = x;
            else
                total2 = sumOfAP((float)x,(float)x,(float)term2);


            ans = total - total2;
            cout <<ans << endl;
        }
        else if(x%y==0 || y%x==0)
        {
            if(term2==1)
                total2 = x;
            else
                total2 = sumOfAP((float)x,(float)x,(float)term2);

            if(term3 == 1)
                total3 = y;
            else
                total3 = sumOfAP((float)y,(float)y,(float)term3);

            if(total2>total3)
                ans = total - total2;
            else
                ans = total - total3;

            cout <<ans << endl;
          //  cout << total << " " << total2 <<" " << total3 << " "<<ans << endl;
        }

    }




    return 0;
}

