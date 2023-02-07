#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

unordered_set<string> allLCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int LCS[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    int index = LCS[m][n];
    int temp = index;
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    unordered_set<string> res;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }
    string temp_string = "";
    for (int i = 0; i < temp; i++)
    {
        temp_string += lcs[i];
    }
    res.insert(temp_string);
    return res;
}

int main()
{
    string X="abcdefsadlkfjsl", Y= "sdklfjlabcdef";
    cin >> X >> Y;
    unordered_set<string> result = allLCS(X, Y);
    for (auto x : result)
        cout << x << endl;
    return 0;
}

