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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + M);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            y--;
            G[i].push_back(y + N);
            G[y + N].push_back(i);
        }
    }

    // 0...N-1 : 集合x, N...N+M-1:整数y-N
    int s = N, t = M + N - 1;
    queue<int> que;
    que.push(s);
    vector<int> dist(N + M, -1);
    dist[s] = 0;
    while (que.size()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    cout << dist[t] / 2 - 1 << endl;
    return 0;
}