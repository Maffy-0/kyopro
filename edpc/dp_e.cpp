#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    int m = 1e5 + 10;
    vector dp(n + 1, vector<ll>(m, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j - v[i] >= 0) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] <= W) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}