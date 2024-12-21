#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};


void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
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

signed main(void) {
    fast_io();
    long N;
    cin >> N;
    int ans = 0;
    // p^8
    // p^2 q^2
    long ma = 2000000;
    auto primes = getPrimes(ma);

    int m = primes.size();
    for (int i = 0; i < m; i++) {
        long x = primes[i];
        if (x * x * x * x > N) break;
        if (x <= 40 && x * x * x * x * x * x * x * x <= N) ans++; 
        for (int j = i + 1; j < m; j++) {
            long y = primes[j];
            if (x * x * y * y <= N) ans++;
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}