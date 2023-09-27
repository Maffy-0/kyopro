#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int Q, K, X;
char C;
mint dp[5050];

int main(void) {
    fast_io();
    cin >> Q >> K;
    dp[0] = 1;
    while (Q--) {
        cin >> C >> X;
        if (C == '+') {
            for (int i = K; i >= X; i--) {
                dp[i] += dp[i - X];
            }
        } else {
            for (int i = X; i <= K; i++) {
                dp[i] -= dp[i - X];
            }
        }
        cout << dp[K].val() << '\n';
    }
    return 0;
}