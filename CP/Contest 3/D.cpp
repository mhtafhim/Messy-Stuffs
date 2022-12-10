#include<bits/stdc++.h>

using namespace std;

 bool is_Subsequence(string subse, string word) {
        int j=0;
        for(int i=0;i<subse.size();i++)
		{
            if(word[j]==subse[i])j++;
        }
      return (j==word.size())?true : false;
    }

int main()
{
    int n,q;
    cin >> n;


    string arr;
    cin >> arr;
    string arr2;

    cin >> q;

    while(q--)
    {
       cin >>arr2;

       if(is_Subsequence(arr2,arr))
        cout<<"yes"<<endl;
       else
        cout<<"NO"<<endl;


    }

    return 0;
}
