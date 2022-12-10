#include <bits/stdc++.h>

using namespace std;






int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    int highest= -100000000000;
    int index;
    for(int i = 1; i<=N ; i++)
    {
        int temp;
        cin >>temp;
        if(temp > highest)
        {
            highest = temp;
            index = i;
        }

    }
    cout << index << endl;
}

