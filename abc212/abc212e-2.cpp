#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<mint> dp(n);
    dp[0] = 1;
    for (int t = 0; t < k; t++) {
        vector<mint> dp2(n);
        swap(dp, dp2);
        mint sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dp2[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i] = sum;
            dp[i] -= dp2[i];
            for (int v : g[i]) {
                dp[i] -= dp2[v];
            }
        }
    }
    cout << dp[0].val() << endl;
    return 0;
}