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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    vector<int> dp(n);
    vector<bool> vis(n);
    auto dfs = [&](auto dfs, int i) -> int {
        if (vis[i]) {
            return dp[i];
        }
        vis[i] = true;
        int res = 0;
        for (auto ni : g[i]) {
            res = max(res, dfs(dfs, ni) + 1);
        }
        return dp[i] = res;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(dfs, i));
    }
    cout << ans << endl;
    return 0;
}