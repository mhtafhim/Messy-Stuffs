#include <bits/stdc++.h>
using namespace std;
int main()
{
    string plainText, key, cipher;
    getline(cin, plainText);
    cin >> key;
    int keyLen = key.length();
    plainText.erase(remove(plainText.begin(), plainText.end(), ' '), plainText.end());
    int need = (keyLen - (plainText.length()%keyLen));
    for (int i = 0; i < need; i++)
        plainText += 'x';

    vector<pair<char, int>> pattern(keyLen);
    for (int i = 0; i < keyLen; i++)
        pattern[i] = {key[i], i};
    sort(pattern.begin(), pattern.end());

    int row = plainText.length() / keyLen;
    for (int i = 0; i < keyLen; i++)
        for (int j = 0; j < row; j++)
            cipher += plainText[j * keyLen + pattern[i].second];
    cout << cipher << endl;
    return 0;
}
