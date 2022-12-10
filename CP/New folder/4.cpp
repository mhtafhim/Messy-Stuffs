#include<iostream>
using namespace std;

int main()
{
    long long int n,q;
    cin>>n;
    char str[n];
    cin>>str;
    cin>>q;
    while(q--)
    {
        char str2[n];
        cin>>str2;
        bool flag = false;
        for(int i=0; str[i]!='\0'; i++)
        {
            flag = false;
            long long int k =i;
            for(int j=0;;)
            {
                if(str2[j]=='\0')
                {
                    flag = true;
                    break;
                }
                if(str[k]=='\0')
                {
                    break;
                }
                if(str[k]!=str2[j])
                {
                    k++;
                    continue;
                }
                j++;
                k++;
            }
            if(flag)
            {
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
