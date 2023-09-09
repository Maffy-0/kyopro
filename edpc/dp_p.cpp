#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector dp(n, vector<mint> (2));
    auto dfs = [&](auto f, int i, int p = -1) -> void {
        dp[i][0] = dp[i][1] = 1;
        for (int ni : tree[i]) if (p != ni) {
            f(f, ni, i);
            dp[i][0] *= dp[ni][0] + dp[ni][1];
            dp[i][1] *= dp[ni][0];
        }
    };
    dfs(dfs, 0);
    mint ans = dp[0][0] + dp[0][1];
    cout << ans.val() << endl;
    return 0;
}