#include <iostream>
#include <vector>

using namespace std;

int knapsack(int n, int W, vector<int> wt, vector<int> val)
{
    vector<vector<int>> V(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                V[i][w] = 0;
            else if (wt[i - 1] <= w)
                V[i][w] = max(val[i - 1] + V[i - 1][w - wt[i - 1]], V[i - 1][w]);
            else
                V[i][w] = V[i - 1][w];
        }
    }

    vector<int> chosen;
    int i = n, w = W;
    while (i > 0 && w > 0)
    {
        if (V[i][w] != V[i - 1][w])
        {
            chosen.push_back(i);
            w = w - wt[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }

    cout << "Chosen items: ";
    for (int i = chosen.size() - 1; i >= 0; i--)
        cout << chosen[i] << " ";
    cout << endl;

    return V[n][W];
}

int main()
{
    int n = 3, W = 50;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    cout << "Maximum value: " << knapsack(n, W, wt, val) << endl;

    return 0;
}

