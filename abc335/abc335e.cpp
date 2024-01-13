#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void standard_bfs(const vector<vector<int>> &g, vector<int> &dist, const vector<int> &cost, int start) {
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
            dist[nv] = dist[v] + A;
            que.push(nv);
        }
    }
}

int main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dist(N, -1);
    standard_bfs(G, dist, A, 0);
    return 0;
}