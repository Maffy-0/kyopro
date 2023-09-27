#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, K;
int P[2020], D[2020];
vector<int> G[2020];

int main(void) {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> P[i] >> D[i];
        P[i]--;
    }

    auto bfs = [&](int i) {
        queue<int> que;
        que.push(i);
        vector<int> dist(N, -1);
        dist[i] = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int nv : G[v]) {
                if (dist[nv] != -1) {
                    continue;
                }
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        return dist;
    };

    vector<vector<int>> ds(N);
    for (int i = 0; i < N; i++) {
        ds[i] = bfs(i);
    }
    string ans(N, '1');
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            if (ds[P[i]][j] < D[i]) {
                ans[j] = '0';
            }
        }
    }
    const int inf = (int) 1e9;
    for (int i = 0; i < K; i++) {
        int now = inf;
        for (int j = 0; j < N; j++) {
            if (ans[j] == '1') {
                now = min(now, ds[P[i]][j]);
            }
        }
        if (now != D[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    cout << ans << endl;
    return 0;
}