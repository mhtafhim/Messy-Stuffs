
#include<bits/stdc++.h>

using namespace std;


int main()
{
    string x;

    cin >> x;

    int s = x.length();
    bool flag1=false,flag2 = false, flag3 = false;
    int counter = 0;

    for(int i =0; i<s; i++)
    {
        if(x[i]>='A' && x[i]<='Z')
            flag1= true;

        if(x[i]>='a' && x[i]<='z')
            flag2= true;

        if(x[i]>='0' && x[i]<='9')
            flag3= true;


        if(flag1 == true && flag2 == true && flag3 == true)
        {
            flag1=false;
            flag2 = false ;
            flag3 = false;
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
