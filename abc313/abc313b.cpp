#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
    }
    for (int i = 0; i < n; i++) {
        vector<bool> vis(n, false);
        vis[i] = true;
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto nv : g[v]) {
                if (vis[nv]) {
                    continue;
                }
                vis[nv] = true;
                que.push(nv);
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= vis[i];
        }
        if (ok) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}