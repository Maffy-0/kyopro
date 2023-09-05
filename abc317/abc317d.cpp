#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<int> need(n);
    for (int i = 0; i < n; i++) {
        need[i] = max(0, (x[i] + y[i] + 1) / 2 - x[i]);
    }
    int sum = accumulate(z.begin(), z.end(), 0);
    const ll inf = (ll)1e18;
    vector<ll> dp(sum + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = sum - z[i]; j >= 0; j--) {
            dp[j + z[i]] = min(dp[j + z[i]], dp[j] + need[i]);
        }
    }
    ll ans = inf;
    for (int i = 0; i <= sum; i++) {
        if (i > sum - i) {
            ans = min(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}