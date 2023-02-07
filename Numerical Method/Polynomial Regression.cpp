
#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the coefficients of polynomial regression
void polynomial_regression(double x[], double y[], int n, int degree)
{
    double xi[2 * degree + 1];
    for (int i = 0; i < 2 * degree + 1; i++)
    {
        xi[i] = 0;
        for (int j = 0; j < n; j++)
            xi[i] = xi[i] + pow(x[j], i);
    }

    double yi[degree + 1];
    for (int i = 0; i < degree + 1; i++)
    {
        yi[i] = 0;
        for (int j = 0; j < n; j++)
            yi[i] = yi[i] + pow(x[j], i) * y[j];
    }

    double a[degree + 1][degree + 2];
    for (int i = 0; i < degree + 1; i++)
    {
        for (int j = 0; j < degree + 1; j++)
            a[i][j] = xi[i + j];

        a[i][degree + 1] = yi[i];
    }

    int m = degree + 1;
    for (int i = 0; i < m; i++)
    {
        for (int k = i + 1; k < m; k++)
        {
            if (a[i][i] < a[k][i])
            {
                for (int j = 0; j <= m; j++)
                {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }

        for (int k = i + 1; k < m; k++)
        {
            double t = a[k][i] / a[i][i];
            for (int j = 0; j <= m; j++)
                a[k][j] = a[k][j] - t * a[i][j];
        }
    }

    for (int i = m - 1; i >= 0; i--)
    {
        double s = 0;
        for (int j = i; j <= m - 1; j++)
            s = s + a[i][j] * a[j][m];

        a[i][m] = (a[i][m] - s) / a[i][i];
    }

    cout << "The coefficients of the polynomial regression are: " << endl;
    for (int i = 0; i < m; i++)
        cout << "a" << i << " = " << a[i][m] << endl;
}

int main()
{
    int n, degree;
    cout << "Enter the number of data: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter the x and y values: " << endl;
    for (int i = 0; i < n; i
