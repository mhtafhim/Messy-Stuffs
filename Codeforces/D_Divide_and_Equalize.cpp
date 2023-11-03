#include <bits/stdc++.h>

using i64 = long long;
std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

constexpr int V = 1E6;

int cnt[V + 1];

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> stk;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        
        while (x > 1) {
            int p = minp[x];
            x /= p;
            stk.push_back(p);
            cnt[p]++;
        }
    }
    
    bool ok = true;
    for (auto x : stk) {
        if (cnt[x] % n) {
            ok = false;
        }
        cnt[x] = 0;
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    sieve(V);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}