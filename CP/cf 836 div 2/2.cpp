
#include <bits/stdc++.h>

using namespace std;

bool check(vector<char> v)
{
    int sz = v.size();
    for(int i =0; i<sz/2; i++)
    {
        if(v[i]!=v[sz-1-i])
            return false;
    }
    return true;
}



string getPalindrome(string str)
{


    unordered_map<char, int> hmap;
    for (int i = 0; i < str.length(); i++)
        hmap[str[i]]++;

    int oddCount = 0;
    char oddChar;
    for (auto x : hmap) {
        if (x.second % 2 != 0) {
            oddCount++;
            oddChar = x.first;
        }
    }


    if (oddCount > 1
        || oddCount == 1 && str.length() % 2 == 0)
        return "NO PALINDROME";


    string firstHalf = "", secondHalf = "";
    for (auto x : hmap) {


        string s(x.second / 2, x.first);

        firstHalf = firstHalf + s;
        secondHalf = s + secondHalf;
    }

    return (oddCount == 1)
               ? (firstHalf + oddChar + secondHalf)
               : (firstHalf + secondHalf);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<char> v;
        string s2;

        for(int i =0; i<s.length(); i++)
        {
            s2.push_back(s[i]);
            s2.push_back(s[i]);
        }

       string ans =  getPalindrome(s2);


       cout << ans << endl;


    }


    return 0;
}
