#include <bits/stdc++.h>
#include <atcoder/all>
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
    vector dp(n + 1, vector<ll> (W + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j - w[i] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}