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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    const int m = 20;
    auto dist = [&](int i, int j) -> double {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        return hypot(dx, dy);
    };
    const double INF = 1e18;
    vector dp(n, vector<double>(m, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ni = i + 1, nj = j; ni < n && nj < m; ni++, nj++) {
                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + dist(i, ni));
            }
        }
    }
    double ans = dp[n - 1][0];
    for (int j = 1; j < m; j++) {
        ans = min(ans, dp[n - 1][j] + (1 << (j - 1)));
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}