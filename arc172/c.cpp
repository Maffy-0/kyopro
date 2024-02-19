#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

long dp[1010101][3][2];
signed main(void) {
    fast_io();
    long N;
    string S;
    cin >> N >> S;
    long x = 0L;
    dp[0][0][0] = 1;
    int p = (S[0] == 'A' ? 0 : 2);
    dp[0][p][1] = 1;
    for (int i = 1; i < N; i++) {
        x += (S[i] == 'A' ? -1 : 1);
        if (abs(x) >= 2)
            continue;
        long j = x + 1;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 2; l++) {
                dp[i][k][l] += dp[i - 1][k][l];
            }
        }
        if (S[0] == 'A') {
            if (x == 1) {
                chmax(dp[i][j][1], dp[i - 1][j - 1][0] + 1);
            } else if (x == 0) {
                chmax(dp[i][j][1], dp[i - 1][j - 1][0] + 1);
            }
        } else {
            if (x == 1) {

            } else if (x == 0) {
                chmax(dp[i][j][1], dp[i - 1][j + 1][0] + 1);
            } else {
                chmax(dp[i][j][1], dp[i - 1][j + 1][0] + 1);
            }
        }
    }
    long ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += dp[N - 1][i][1];
    }
    cout << ans;
    return 0;
}