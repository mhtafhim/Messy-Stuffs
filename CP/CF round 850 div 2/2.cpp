#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 0;
        int k = int(sqrt(2 * n));
        if (k * (k + 1) > 2 * n) {
            k--;
        }
        a = k * (k + 1) / 2;
        int b = n - a;
        cout << a << " " << b << endl;
    }
    return 0;
}
