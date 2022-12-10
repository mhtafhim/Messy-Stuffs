#include<bits/stdc++.h>

using namespace std;


int main()
{

    int t;
    cin>>t;


    while(t--)
    {
        int n ;
        cin >>n;

        vector< pair<int,string>> vec;

        for(int i =0; i<n ; i++)
        {
            string x;
            int temp;
            cin >>x >>temp;
            vec.push_back( make_pair(temp,x));
        }

        sort(vec.begin(),vec.end());

        for(int i = n-1; i>=0 ; i--)
        {
            cout<<vec[i].second << endl;
        }

    }

    return 0;
}
