#include<bits/stdc++.h>

using namespace std;



int main()
{
    vector<int> v;
    vector<int> :: iterator it;
    vector<int>:: reverse_iterator it2;

    for(int i =0; i<20; i++)
        v.push_back(i+1);


        it = v.end();
        it2 = v.rbegin();


    if(it==it2)
        cout<< "same" << endl;
    else
        cout << "fck" << endl


             return 0;
}
