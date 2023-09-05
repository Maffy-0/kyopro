#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int mx = 5050;
ll n, m, x[mx], bonus[mx], dp[mx][mx];

int main(void) {
    fast_io();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        int c, y;
        cin >> c >> y;
        bonus[c] += y;
    }
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++) {
            dp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x[i] + bonus[j]);
            dp[i][0] = max(dp[i][0], dp[i - 1][j - 1]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}