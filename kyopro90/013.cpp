#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
const long INF = 1e18;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

struct Edge {
    long to;
    long cost;
};

// ダイクストラ法
// distは頂点数と同じサイズ、すべてINFで初期化
// 頂点startIndexから頂点targetIndexまでの最短経路をpathに収納する
void dijkstra(const vector<vector<Edge>> &g, vector<long> &dist, int startIndex, int targetIndex, vector<long> &path) {
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> que;
    dist[startIndex] = 0;
    que.emplace(dist[startIndex], startIndex);
    vector<long> pre((int)dist.size(), -1);
    while (!que.empty()) {
        auto [distance, from] = que.top();
        que.pop();
        if (dist[from] < distance) {
            continue;
        }
        for (const auto &e : g[from]) {
            long d = dist[from] + e.cost;
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

signed main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        long u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    vector<long> dist(N, INF), dist2(N, INF), path(N);
    dijkstra(G, dist, 0, N - 1, path);
    dijkstra(G, dist2, N - 1, 0, path);
    for (int i = 0; i < N; i++) {
        cout << dist[i] + dist2[i] << '\n';
    }
    return 0;
}