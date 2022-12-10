#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long int n,q;
    long long int counter = 0;
    vector<int> v;
    cin >>n>>q;
    int temp ;
    for(long long int i =0; i<n ; i++)
    {
        cin >>temp ;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    while(q--)
    {
        counter = 0;
        int x,y;
        cin >>x>>y;
        std::vector<int>::iterator start,i;
        start = lower_bound(v.begin(),v.end(),x);
        for(i = start;;i++)
        {
            if(x<=*i && y >=*i)
                counter++;
            else
                break;

        }
        cout << counter << endl;
    }

    return 0;
}
