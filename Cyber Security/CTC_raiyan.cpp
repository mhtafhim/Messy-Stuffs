#include <bits/stdc++.h>
using namespace std;
int main()
{
    string plain, key;
    cout << "Plain Text: ";
    getline(cin, plain);
    cout << "Keyword: ";
    cin >> key;
    plain.erase(remove(plain.begin(), plain.end(), ' '), plain.end());
    int column = key.length();
    int row = ceil(plain.length() / (column * 1.0));
    char arr[row][column];
    int k = 0;
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            arr[i][j] = plain[k];
            k++;
            if (k == plain.length())
                break;
        }
        if (k == plain.length())
            break;
    }
    for (j++; j < column; j++)
    {
        arr[i][j] = 'x';
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    vector<tuple<char, int>> seq;
    for (int i = 0; i < column; i++)
        seq.push_back({key[i], i});
    sort(seq.begin(), seq.end());
    cout << "Cipher Text: ";
    for (auto i : seq)
    {
        int k = get<1>(i);
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][k];
        }
    }
}