#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

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

    vector<pair<long long, long long>> prime_factorize(long long n) {
        vector<pair<long long, long long>> res;
        for (long long p = 2; p * p <= n; p++) {
            if (n % p != 0) {
                continue;
            }
            long long e = 0;
            while (n % p == 0) {
                e++;
                n /= p;
            }
            res.emplace_back(p, e);
        }
        if (n != 1) {
            res.emplace_back(n, 1);
        }
        return res;
    }

    vector<long long> divisors(long long n) {
        vector<long long> res;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                res.push_back(i);
                if (i * i != n) {
                    res.push_back(n / i);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    bool isSquare(long long n) {
        long long d = (long long)sqrt(n) - 1;
        while (d * d < n) {
            ++d;
        }
        return d * d == n;
    }

    vector<long long> getPrimes(long long n) {
        vector<long long> primes;
        vector<bool> isP(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (isP[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    isP[j] = false;
                }
                primes.emplace_back(i);
            }
        }
        return primes;
    }

    string to_base_string(int x, int base) {
        assert(base >= 2 && base <= 16);
        if (x == 0) {
            return "0";
        }
        const string table = "0123456789abcdef";
        string res;
        int y = x;
        do {
            int div = y / base;
            int mod = y % base;
            res = table[mod] + res;
            y = div;
        } while (y != 0);
        return res;
    }
    
    long long factorial(long long n) {
        if (n == 1) {
            return 1;
        } else {
            return factorial(n - 1) * n;
        }
    }
};

int main(void) {
    fast_io();
    Integer integer;
    int N;
    cin >> N;
    string S = integer.to_base_string(N, 2);
    reverse(S.begin(), S.end());
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') {
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}