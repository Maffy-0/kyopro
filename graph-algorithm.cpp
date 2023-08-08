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
void dijkstra(const vector<vector<edge>> &g, vector<ll> &dist, int startIndex, int targetIndex, vector<ll> &path) {
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

// 木に対するDFS
// 通った順をresに記録する(abc213-d)
void euler_tour(const vector<vector<int>> &g, vector<int> &res, int v, int pre = -1) {
    res.push_back(v + 1);
    for (auto nv : g[v]) {
        if (nv == pre) {
            continue;
        }
        euler_tour(g, res, nv, v);
        res.push_back(v + 1);
    }
}

// 標準的なdfsのテンプレート
// seenはfalseで初期化
void standard_dfs(const vector<vector<int>> &g, vector<bool> &seen, int v) {
    seen[v] = true;
    for (auto nv : g[v]) {
        if (seen[nv]) {
            continue;
        }
        standard_dfs(g, seen, nv);
    }
}

// 標準的なbfsのテンプレート
// distは-1で初期化
void standard_bfs(const vector<vector<int>> &g, vector<int> &dist, int start) {
    queue<int> que;
    que.push(start);
    dist[start] = 0;
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : g[v]) {
            if (dist[nv] != -1) {
                continue;
            }
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
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
        //g[v].push_back(u);
    }
    return 0;
}