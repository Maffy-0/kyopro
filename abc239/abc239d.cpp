#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int A, B, C, D;
struct Integer {
    long long n;

    bool isPrime(long long n) {
        assert(n >= 1);
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
};

int main(void) {
    fast_io();
    cin >> A >> B >> C >> D;
    Integer integer;
    for (int i = A; i <= B; i++) {
        bool find_prime = false;
        for (int j = C; j <= D; j++) {
            int k = i + j;
            if (integer.isPrime(k)) {
                find_prime = true;
                break;
            }
        }
        if (!find_prime) {
            cout << "Takahashi\n";
            return 0;
        }
    }
    cout << "Aoki\n";
    return 0;
}