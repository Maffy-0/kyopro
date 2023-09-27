#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, X[303030], Y[303030];

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    vector dp(N + 1, vector<long long>(2));
    for (int i = 0; i < N; i++) {
        if (X[i] == 0) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + Y[i]);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + Y[i]);
        } else {
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + Y[i]);
        }
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
    }
    long long ans = max(dp[N][0], dp[N][1]);
    cout << ans << endl;
    return 0;
}