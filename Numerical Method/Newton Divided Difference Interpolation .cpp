
#include<bits/stdc++.h>
using namespace std;

double x[10001], y[10001][10001];
int n;
double xp, yp;

void divided_difference_table() {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
        }
    }
}

double newton_divided_difference(double xp) {
    yp = y[0][0];
    for (int i = 1; i < n; i++) {
        double product = 1;
        for (int j = 0; j < i; j++) {
            product *= (xp - x[j]);
        }
        yp += product * y[0][i];
    }
    return yp;
}

int main() {
    cout << "Enter the number of data points: ";
    cin >> n;
    cout << "Enter the data points: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i][0];
    }
    cout << "Enter the value of Xp: ";
    cin >> xp;
    divided_difference_table();
    cout << "The value of Yp is: " << newton_divided_difference(xp) << endl;
    return 0;
}
