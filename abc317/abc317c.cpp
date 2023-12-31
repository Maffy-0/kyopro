#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = 1e18;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector cost(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        cost[u][v] = cost[v][u] = w;
    }
    int ans = 0;
    vector<bool> vis(n);
    auto f = [&](auto f, int i, int sum) -> void {
        vis[i] = true;
        ans = max(ans, sum);
        for (int j = 0; j < n; j++) {
            if (cost[i][j] > 0 && !vis[j]) {
                f(f, j, sum + cost[i][j]);
            }
        }
        vis[i] = false;
    };
    for (int i = 0; i < n; i++) {
        f(f, i, 0);
    }
    cout << ans << endl;
    return 0;
}