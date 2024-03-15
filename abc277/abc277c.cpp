#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N;
    cin >> N;
    map<int, vector<int>> G;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    map<int, int> vis;
    vis[1] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto nv : G[v]) {
            if (vis[nv] == true) continue;
            vis[nv] = true;
            q.push(nv);
        }
    }
    auto [mx, _] = *vis.rbegin();
    cout << mx << endl;
    return 0;
}