#include <bits/stdc++.h>

using namespace std;






int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long int a,b,c,d,e,f;

    cin >>a>>b>>c>>d>>e>>f;

    unsigned long long int multi = ((a*b*c)-(d*e*f));

    cout << multi << endl;
    if(multi < 998244353)
        cout << multi;
    else
        cout << (unsigned long long int)((a*b*c)-(d*e*f))%998244353 << endl;

    return 0;

}

