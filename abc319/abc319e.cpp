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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> p(n - 1), t(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> p[i] >> t[i];
    }
    int m = 840;
    vector<ll> dp(m);
    for (int i = 0; i < m; i++) {
        dp[i] = i + x;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            dp[j] = (dp[j] + p[i] - 1) / p[i] * p[i] + t[i];
        }
    }
    for (int i = 0; i < m; i++) {
        dp[i] += y;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll p;
        cin >> p;
        ll ans = dp[p % m] + (p / m) * m;
        cout << ans << '\n';
    }
    return 0;
}