#include<bits/stdc++.h>
using namespace std;

// Function to calculate the greatest common divisor
long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular inverse
long long int modInverse(long long int a, long long int m) {
    long long int m0 = m, t, q;
    long long int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to calculate the power with modulus
long long int powMod(long long int a, long long int b, long long int n) {
    long long int res = 1;
    a = a % n;

    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % n;
        b = b / 2;
        a = (a * a) % n;
    }

    return res;
}

int main() {
    long long int p, q, n, phi, e, d;

    // Choose two prime numbers
    p = 73;
    q = 151;

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose public key exponent e
    e = 2;
    while (gcd(e, phi) != 1)
        e++;

    // Calculate private key exponent d
    d = modInverse(e, phi);

    cout << "Public Key: (" << n << ", " << e << ")" << endl;
    cout << "Private Key: " << d << endl;
    


   


    long long int message = 3314;
    cout << "Message: " << message << endl;

    // Encryption
    long long int ciphertext = powMod(message, e, n);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decryption
    long long int decryptedtext = powMod(ciphertext, d, n);
    cout << "Decrypted Message: " << decryptedtext << endl;

    return 0;
}