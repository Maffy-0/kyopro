#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

struct Integer {
    long long n;

    bool isPrime(long long n) {
        if (n == 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }
        double a = sqrt(n);
        for (long long i = 3; i <= a; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    long long isSquare(long long n) {
        long long d = (long long)sqrt(n) - 1;
        while (d * d < n) {
            ++d;
        }
        if (d * d == n) {
            return d;
        } else {
            return -1;
        }
    }
};

void solve(long long n) {
    Integer I;
    for (long long i = 1; i <= 1e6; i++) {
        if (I.isPrime(i)) {
            long long d = I.isSquare(n / i);
            if (d != -1 && I.isPrime(d)) {
                cout << d << " " << i << endl;
                return;
            }
        }
        if (I.isSquare(i) != -1) {
            long long d = I.isSquare(i);
            if (n % i == 0 && I.isPrime(n / i) && I.isPrime(d)) {
                cout << d << " " << n / i << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}

long long T, N;

int main(void) {
    fast_io();
    cin >> T;
    while (T--) {
        cin >> N;
        solve(N);
    }
    return 0;
}