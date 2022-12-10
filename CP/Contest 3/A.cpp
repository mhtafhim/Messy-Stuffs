#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    cin >>r>>c;
    int a,b;
    bool flag = true;
    char arr[r][c];
    for(int i=0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='=' && flag ==true )
            {
                a=i;
                b=j;
                flag = false;
            }
        }
    }
    int temp1 = a, temp2 = b;
    while(1)
    {
        if( arr[temp1][temp2] !='=')
            break;

        temp2++;
    }

    int counter = 0;
    for(int i = 0;i<temp1;i++)
    {
        for(int j = b ; j<temp2 ; j++)
        {
            if(arr[i][j]=='O')
                counter++;
        }
    }

    cout << counter << endl;
    return 0;
}

