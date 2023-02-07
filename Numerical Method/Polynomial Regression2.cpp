
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, degree;
double x0;
vector<double> x, y, a;
vector<vector<double>> A;

double sumX(int power)
{
    double result = 0;
    for (int i = 0; i < n; i++)
        result += pow(x[i], power);
    return result;
}

double sumXY(int power)
{
    double result = 0;
    for (int i = 0; i < n; i++)
        result += pow(x[i], power) * y[i];
    return result;
}

void GaussElimination()
{
    for (int i = 0; i <= degree; i++)
    {
        for (int j = i + 1; j <= degree; j++)
        {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= degree + 1; k++)
                A[j][k] -= factor * A[i][k];
        }
    }

    for (int i = degree; i >= 0; i--)
    {
        a[i] = A[i][degree + 1];
        for (int j = i - 1; j >= 0; j--)
            A[j][degree + 1] -= A[j][i] * a[i];
        a[i] /= A[i][i];
    }
}

int main()
{
    cout << "Enter number of data points: ";
    cin >> n;
    x.resize(n);
    y.resize(n);
    cout << "Enter x and y values: " << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    cout << "Enter degree of polynomial: ";
    cin >> degree;
    x0 = n;
    A.resize(degree + 1);
    a.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
    {
        A[i].resize(degree + 2);
        for (int j = 0; j <= degree; j++)
            A[i][j] = sumX(i + j);
        A[i][degree + 1] = sumXY(i);
    }
    GaussElimination();
    cout << "Coefficients: " << endl;
    for (int i = 0; i <= degree; i++)
        cout << "a" << i << ": " << a[i] << endl;
    return 0;
}
