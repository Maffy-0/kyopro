#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

struct Integer {
    ll n;

    bool isPrime(ll n) {
        assert(n >= 1);
        if (n == 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }
        double a = sqrt(n);
        for (ll i = 3; i <= a; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<pair<ll, ll>> prime_factorize(ll n) {
        vector<pair<ll, ll>> res;
        for (ll p = 2; p * p <= n; p++) {
            if (n % p != 0) {
                continue;
            }
            ll e = 0;
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

    vector<ll> divisors(ll n) {
        vector<ll> res;
        for (ll i = 1; i * i <= n; i++) {
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

    bool isSquare(ll n) {
        ll d = (ll)sqrt(n) - 1;
        while (d * d < n) {
            ++d;
        }
        return d * d == n;
    }

    vector<ll> getPrimes(ll n) {
        vector<ll> primes;
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

    ll nc2(ll n) { return n * (n - 1) / 2; }

    ll nc3(ll n) { return n * (n - 1) * (n - 2) / 6; }

    ll factorial(ll n) {
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
    return 0;
}