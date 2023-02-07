#include<bits/stdc++.h>
using namespace std;

double X[10001], Y[10001];
int n;
double Xp, Yp;

double lagrange(double Xp) {
    double p = 1;
    Yp = 0;
    for (int i = 0; i < n; i++) {
        p = 1;
        for (int j = 0; j < n; j++) {
            if (j != i)
                p = p * (Xp - X[j]) / (X[i] - X[j]);
        }
        Yp += p * Y[i];
    }
    return Yp;
}

int main() {
    cout << "Enter the number of data points: ";
    cin >> n;
    cout << "Enter the data points: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }
    cout << "Enter the value of Xp: ";
    cin >> Xp;
    cout << "The value of Yp is: " << lagrange(Xp) << endl;
    return 0;
}
