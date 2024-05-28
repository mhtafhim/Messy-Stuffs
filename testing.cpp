#include <bits/stdc++.h>
using namespace std;

int main()
{

    int matrix[3][3] = {{1, 2, 0},
                        {0, 5, 6},
                        {7, 0, 9}};

    int cnt = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
