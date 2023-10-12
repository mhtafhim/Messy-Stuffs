#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define all(x) x.begin(), x.end()

// Function to check if two strings are equal character by character
bool check(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

// Function to solve the problem
void solve(int cs)
{
    // Input two strings
    string ss[2];
    cin >> ss[0] >> ss[1];

    // Initialize a vector to track blocks and get the string size
    vector<int> block(ss[0].size());
    int size = ss[0].size();

    // Input the number of test cases and queries
    int t, q;
    cin >> t >> q;

    while (q--)
    {
        // Input the query type
        int sel;
        cin >> sel;

        if (sel == 1)
        {
            // Query type 1: Update blocks
            // Decrease block values, if any, and set a block to t
            for (int i = 0; i < size; i++)
            {
                if (block[i] > 0)
                    block[i]--;
            }
            int inx;
            cin >> inx;
            block[--inx] = t;
        }
        else if (sel == 2)
        {
            // Query type 2: Swap characters
            // Swap characters if both blocks are empty
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            if (block[b] == 0 && block[d] == 0)
            {
                swap(ss[a][b], ss[c][d]);
            }
            // Decrease block values, if any
            for (int i = 0; i < size; i++)
            {
                if (block[i] > 0)
                    block[i]--;
            }
        }
        else if (sel == 3)
        {
            // Query type 3: Check if the two strings are equal
            // Decrease block values, if any
            for (int i = 0; i < size; i++)
            {
                if (block[i] > 0)
                    block[i]--;
            }

            // Compare the two strings character by character
            bool ok = true;
            for (int i = 0; i < size; i++)
            {
                if (ss[0][i] != ss[1][i] && block[i] == 0)
                {
                    ok = false;
                    break;
                }
            }

            // Output "YES" if strings are equal, otherwise "NO"
            (ok ? cout << "YES" : cout << "NO");
            cout << endl;
        }
    }
}

int main()
{
    // Fast input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input the number of test cases
    int t;
    cin >> t;

    // Solve each test case
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}
