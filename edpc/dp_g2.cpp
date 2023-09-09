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

// トポロジカルソート
// 返り値のvectorのサイズ != 頂点数で閉路検出
vector<ll> topological_sort(const vector<vector<ll>> &g) {
    vector<ll> res;
    ll n = g.size();
    vector<ll> indeg(n);
    for (ll i = 0; i < n; i++) {
        for (auto v : g[i]) {
            indeg[v]++;
        }
    }
    queue<ll> que;
    for (ll i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        res.push_back(v);
        for (auto nv : g[v]) {
            indeg[nv]--;
            if (indeg[nv] == 0) {
                que.push(nv);
            }
        }
    }
    return res;
}

int main(void) {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    auto h = topological_sort(g);
    vector<int> dp(n);
    for (int i = 0; i < (int)h.size(); i++) {
        for (auto to : g[h[i]]) {
            dp[to] = max(dp[to], dp[h[i]] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}