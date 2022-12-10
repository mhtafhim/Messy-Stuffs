#include <bits/stdc++.h>

using namespace std;





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
   // cin >> t;
    while(t--)
    {
        vector<pair<string,int>> dictionary;
        int i=1;
        while(1)
        {
            string temp;
            cin>> temp;
            if(temp == "*")
                break;
            dictionary.push_back(make_pair(temp,i));
            i++;
        }

        for(int i=0;i<dictionary.size();i++)
        {
            cout << dictionary[i].first[0] <<"  " <<dictionary[i].second<< endl;
        }



    }


    return 0;
}
