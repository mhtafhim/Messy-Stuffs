
#include <bits/stdc++.h>


using namespace std;

int m[5][5], bracket[5][5];


void printOptimalParens(int i, int j, int n, int *bracket, int &count)
{
    if (i == j)
    {
        cout << "A" << count++;
        return;
    }
    cout << "(";
    printOptimalParens(i, *((bracket + i * n) + j), n, bracket, count);
    printOptimalParens(*((bracket + i * n) + j) + 1, j, n, bracket, count);
    cout << ")";
}

int MatrixChainOrder(const vector<int> &p, int n)
{

    // Initializing values for diagonal elements
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Chain Length
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {                cout << i-1 << "  "<<k<< " "<<j<<endl;

                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }



    for(int a=1; a<n; a++)
    {
        for(int b=1; b<n; b++)
        {
            cout <<setw(10)<< m[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;



//   cout << "Optimal Parenthesization is : ";
    int count = 1;
    //  printOptimalParens(1, n - 1, n, (int *)bracket, count);

    return m[1][n - 1];
}

int main()
{
    vector<int> p = {5,4,6,2,7};
    int n = p.size();

    // cout << "Minimum number of multiplications is "
//         <<  << endl;
    cout << MatrixChainOrder(p, n);
    return 0;
}
