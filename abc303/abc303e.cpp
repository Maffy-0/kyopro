#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int start = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            start = i;
        }
    }
    vector<int> ans;
    auto dfs = [&](auto dfs, int v, int pre = -1, int d = 0) -> void {
        if (d % 3 == 1) {
            ans.push_back(g[v].size());
        }
        for (int nv : g[v]) {
            if (nv != pre) {
                dfs(dfs, nv, v, d + 1);
            }
        }
    };
    dfs(dfs, start);
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}