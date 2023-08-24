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
    vector<vector<ll>> g(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int p;
            cin >> p;
            p--;
            g[i].push_back(p);
        }
    }

    vector<int> ans;
    vector<bool> vis(n);
    auto dfs = [&](auto dfs, int i) -> void {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        for (auto nv : g[i]) {
            dfs(dfs, nv);
        }
        ans.push_back(i);
    };
    dfs(dfs, 0);
    ans.pop_back();
    for (auto x : ans) {
        cout << x + 1 << endl;
    }
    return 0;
}