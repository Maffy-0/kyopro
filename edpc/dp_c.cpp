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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector dp(n + 1, vector<ll> (3));
    for (int i = 0; i < n; i++) {
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i]);
        dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + a[i]);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + b[i]);
        dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + b[i]);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] + c[i]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + c[i]);
    }
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}