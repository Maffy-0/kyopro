#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, K, A[202020];
long long dp[41][202020];

int main(void) {
    fast_io();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        dp[0][i] = A[i];
    }
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][j] + dp[i][(j + dp[i][j]) % N];
        }
    }
    long long ans = 0;
    for (int i = 0; i < 40; i++) {
        if ((K >> i) & 1) {
            ans += dp[i][ans % N];
        }
    }
    cout << ans << endl;
    return 0;
}