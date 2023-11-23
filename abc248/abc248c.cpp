#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, K;
mint dp[55][5050];

int main(void) {
    fast_io();
    cin >> N >> M >> K;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                if (j + k <= K) dp[i + 1][j + k] += dp[i][k];
            }
        }
    }
    mint ans = 0;
    for (int i = N; i <= K; i++) {
        ans += dp[N][i];
    }
    cout << ans.val() << endl;
    return 0;
}