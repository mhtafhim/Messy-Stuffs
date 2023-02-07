
#include<bits/stdc++.h>
using namespace std;

int n;
double x[10001], y[10001];
double sumX, sumX2, sumY, sumXY;
double a, b;

void calculate_sums() {
    sumX = 0;
    sumX2 = 0;
    sumY = 0;
    sumXY = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }
}

void calculate_ab() {
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
}

int main() {
    cout << "Enter the number of data points: ";
    cin >> n;
    cout << "Enter the data points: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    calculate_sums();
    calculate_ab();
    //double ans = a + b*4;
    cout << "The value of a is: " << a << endl;
    cout << "The value of b is: " << b << endl;
 //   cout << ans << endl;
    return 0;
}
