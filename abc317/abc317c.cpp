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

struct edge {
    ll to;
    ll cost;
};

// ダイクストラ法
// distは頂点数と同じサイズ、すべてINFで初期化
// 頂点startIndexから頂点targetIndexまでの最短経路をpathに収納する
void dijkstra(const vector<vector<edge>> &g, vector<ll> &dist, int startIndex,
              int targetIndex, vector<ll> &path) {
    using Pll = pair<ll, ll>;
    priority_queue<Pll, vector<Pll>, greater<Pll>> que;
    dist[startIndex] = 0;
    que.emplace(dist[startIndex], startIndex);
    vector<ll> pre((int)dist.size(), -1);
    while (!que.empty()) {
        auto [distance, from] = que.top();
        que.pop();
        if (dist[from] < distance) {
            continue;
        }
        for (const auto &e : g[from]) {
            ll d = dist[from] + e.cost;
            if (d < dist[e.to]) {
                pre[e.to] = from;
                dist[e.to] = d;
                que.emplace(dist[e.to], e.to);
            }
        }
    }
    if (dist[targetIndex] != INF) {
        for (int i = targetIndex; i != -1; i = pre[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
    }
    return;
}

int main(void) {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            vector<ll> dist(n, INF);
            vector<ll> path(n);
            dijkstra(g, dist, i, j, path);
            for (int k = 0; k < n; k++) {
                if (dist[k] == INF) continue;
                ans = max(ans, dist[k]);
                cout << dist[k] << " ";
            }
            cout << endl;
        }
    }
    cout << ans << endl;
    return 0;
}