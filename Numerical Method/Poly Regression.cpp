#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1000;

int n;
double x[MAXN], y[MAXN];
int degree;
double xsum[2 * MAXN];
double ysum[MAXN];
double A[MAXN][MAXN];

void readData()
{
    cout << "Enter number of data: ";
    cin >> n;

    cout << "Enter x and y: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    cout << "Enter degree of polynomial: ";
    cin >> degree;
}

void calculateSumOfX()
{
    xsum[0] = (double)n;
    for (int i = 1; i < 2 * degree + 1; i++)
    {
        xsum[i] = 0.0;
        for (int j = 0; j < n; j++)
        {
            xsum[i] += pow(x[j], i);
        }
    }
}

void calculateSumOfY()
{
    for (int i = 0; i < degree + 1; i++)
    {
        ysum[i] = 0.0;
        for (int j = 0; j < n; j++)
        {
            ysum[i] += pow(x[j], i) * y[j];
        }
    }
}

void setMatrixForSolve()
{
    for (int i = 0; i < degree; i++)
    {
        for (int j = 0; j < degree; j++)
        {
            A[i][j] = xsum[i + j];
        }
        A[i][degree] = ysum[i];
    }
}

void gaussianElimination()
{
/*
    cout << endl << endl;

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<=n;j++)
        {
            cout << A[i][j] << "   " ;
        }
        cout << endl;
    }

    cout << endl << endl;

*/
    for (int i = 0; i < degree - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < degree; j++)
        {
            if (fabs(A[j][i]) > fabs(A[maxIndex][i]))
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            for (int j = 0; j <= degree; j++)
            {
                swap(A[i][j], A[maxIndex][j]);
            }
        }
        for (int j = i + 1; j < degree; j++)
        {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= degree; k++)
            {
                A[j][k] -= factor * A[i][k];
            }
        }
    }
/*
    cout << endl << endl;

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<=n;j++)
        {
            cout << A[i][j] << "   " ;
        }
        cout << endl;
    }

    cout << endl << endl;
*/

    for (int i = degree - 1; i >= 0; i--)
    {
        double sum = 0.0;
        for (int j = i + 1; j < degree; j++)
        {
            sum += A[i][j] * A[j][degree];
        }
        A[i][degree] = (A[i][degree] - sum) / A[i][i];
    }
}

int main()
{
    readData();
    calculateSumOfX();
    calculateSumOfY();
    setMatrixForSolve();
    gaussianElimination();

    cout << "The coefficients of the polynomial are: " << endl;
    for (int i = 0; i < degree; i++)
    {
        cout << "a" << i << " = " << A[i][degree] << endl;
    }

    return 0;
}
