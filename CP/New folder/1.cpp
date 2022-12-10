#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    bool arr[n+1]= {false};

    cin >> n>>m;

    int sum = (n*(n+1))/2;
    for(int i = 0;i<m;i++)
    {
        int x;
        cin >>x;
       sum = sum - x;
    }

    cout << sum << endl;

    return 0;
}
