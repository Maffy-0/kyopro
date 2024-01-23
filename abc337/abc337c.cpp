#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    queue<int> que;
    vector<int> dist(N + 1, -1);
    vector<vector<int>> G(N + 1);
    for (int i = 1; i <= N; i++) {
        if (A[i] == -1) {
            que.push(i);
            dist[i] = 0;
        } else {
            G[A[i]].push_back(i);
        }
    }

    while (que.size()) {
        int v = que.front();
        que.pop();
        cout << v << " ";
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            que.push(nv);
            dist[nv] = dist[v] + 1;
        }
    }
    cout << endl;
    return 0;
}