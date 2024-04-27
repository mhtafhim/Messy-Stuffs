#include <bits/stdc++.h>
using namespace std;

int main(){
    string plainText , key, new_plainText,cipher;
    //taking input
    getline(cin,plainText);
    cin >> key;

    //removed space from plain text
    for(int i=0; i < plainText.length();i++)
    {
        if(plainText[i]!=' ')
        new_plainText+=(plainText[i]);
    }

    int len = new_plainText.length();
    int keyLen = key.length();
    int need = keyLen - (len%keyLen);

    //generated key sequence from key
    vector<pair<char,int>> pattern(keyLen);
    for(int i= 0 ; i < keyLen ; i ++)
    {
        pattern[i] = {key[i],i};
    }
    sort(pattern.begin(),pattern.end());

    //added padding to plain text 
    for(int i=0 ; i < need ; i ++)new_plainText+='x';

    //generated cipher text using indexes
    int row = new_plainText.length()/keyLen;
    for(int i = 0 ; i < keyLen;i++)
    {
        for(int j = 0 ; j < row ; j ++)
        {
            int indx = j*keyLen + pattern[i].second;
            cipher+= new_plainText[indx];
        }
    }
    cout << cipher << endl;
    return 0;
}
