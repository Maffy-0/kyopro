#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color(N, -1);
    for (int v = 0; v < N; v++) {
        if (color[v] != -1) continue;
        queue<int> q;
        q.push(v);
        color[v] = 0;
        while (q.size()) {
            int vv = q.front();
            q.pop();
            for (auto nv : G[vv]) {
                if (color[nv] != -1) {
                    if (color[nv] == color[vv]) {
                        cout << "No" << endl;
                        return 0;
                    }
                } else {
                    color[nv] = 1 - color[vv];
                    q.push(nv);
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}