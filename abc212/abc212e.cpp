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
    vector dp(k + 1, vector<mint> (n));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        mint s = 0;
        for (int j = 0; j < n; j++) {
            s += dp[i][j];
        }
        for (int j = 0; j < n; j++) {
            dp[i + 1][j] = s;
            dp[i + 1][j] -= dp[i][j];
            for (int v : g[j]) {
                dp[i + 1][j] -= dp[i][v];
            }
        }
    }
    cout << dp[k][0].val() << endl;
    return 0;
}