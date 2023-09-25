#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int T;
long long N, X, K;

long long count(long long x, long long d) {
    if (x > N) {
        return 0;
    }
    long long l = x, r = x;
    for (int i = 0; i < d; i++) {
        l *= 2;
        r = r * 2 + 1;
        if (l > N) {
            return 0;
        }
    }
    r = min(r, N);
    return r - l + 1;
}

long long solve() {
    cin >> N >> X >> K;
    long long ans = count(X, K);
    while (X > 1 && K >= 2) {
        ans += count(X ^ 1, K - 2);
        K--;
        X >>= 1;
    }
    if (K == 1 && X != 1) {
        ans++;
    }
    return ans;
}

int main(void) {
    fast_io();
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
} 