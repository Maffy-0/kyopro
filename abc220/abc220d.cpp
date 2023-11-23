#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, A[101010];
mint dp[11][101010];

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    dp[A[0]][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            dp[(j + A[i]) % 10][i] += dp[j][i - 1];
            dp[(j * A[i]) % 10][i] += dp[j][i - 1];
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << dp[i][N - 1].val() << '\n';
    }
    return 0;
}