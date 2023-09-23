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
mint dp[1010][1010];

// dp[i][j] i回目にマスjにいる期待値
int main(void) {
    fast_io();
    cin >> N >> M >> K;
    dp[0][0] = 1;
    mint minv = (mint)1 / M;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= M; k++) {
                if (j + k > N) {
                    int nj = N - (j + k - N);
                    dp[i + 1][nj] += dp[i][j] * minv;
                } else {
                    dp[i + 1][j + k] += dp[i][j] * minv;
                }
            }
            
        }
    }
    mint ans = 0;
    for (int i = 0; i <= K; i++) {
        ans += dp[i][N];
    }
    cout << ans.val() << endl;
    return 0;
}