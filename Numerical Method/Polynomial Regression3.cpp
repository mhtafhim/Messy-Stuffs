#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, degree;
double x[MAX], y[MAX], X[2 * MAX][MAX];
double coefficients[MAX];

void calculateSumX() {
    for(int i = 1; i < 2 * degree + 1; i++) {
        for(int j = 0; j < n; j++) {
            X[i][j] = pow(x[j], i);
        }
    }
}

void calculateSumY() {
    for(int i = 0; i < degree + 1; i++) {
        for(int j = 0; j < n; j++) {
            X[i][j] = pow(x[j], i) * y[j];
        }
    }
}

void gaussianElimination() {


    for (int i = 0; i < degree; i++) {
        int pivot = i;

        for (int j = i + 1; j < degree; j++) {
            if (fabs(X[i][j]) > fabs(X[i][pivot])) {
                pivot = j;
            }
        }

        if (pivot != i) {
            for (int j = 0; j <= degree; j++) {
                swap(X[j][i], X[j][pivot]);
            }
        }

        for (int j = i + 1; j < degree; j++) {
            double factor = X[i][j] / X[i][i];
            for (int k = i; k <= degree; k++) {
                X[k][j] -= factor * X[k][i];
            }
        }
    }

    for (int i = degree - 1; i >= 0; i--) {
        coefficients[i] = X[i][degree];
        for (int j = i + 1; j < degree; j++) {
            coefficients[i] -= X[i][j] * coefficients[j];
        }
        coefficients[i] = coefficients[i] / X[i][i];
    }
}

int main() {
    cout << "Enter the number of data: ";
    cin >> n;
    cout << "Enter the values of x: ";
    for(int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter the values of y: ";
    for(int i = 0; i < n; i++) cin >> y[i];
    cout << "Enter the degree of polynomial: ";
    cin >> degree;

    calculateSumX();
    calculateSumY();
    gaussianElimination();

    cout << "The coefficients of the polynomial are: ";
    for(int i = 0; i < degree; i++) {
        cout << coefficients[i] << " ";
    }
    return 0;
}

