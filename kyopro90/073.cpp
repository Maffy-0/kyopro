#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

using mint = modint1000000007;
mint dp[101010][3];

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<char> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto dfs = [&](auto f, int v, int p = -1) -> void {
        mint x = 1, y = 1;
        for (auto nv : G[v]) {
            if (p == nv) {
                continue;
            }
            f(f, nv, v);
            if (C[v] == 'a') {
                x *= (dp[nv][0] + dp[nv][2]);
                y *= (dp[nv][0] + dp[nv][1] + 2 * dp[nv][2]);
            } else {
                x *= (dp[nv][1] + dp[nv][2]);
                y *= (dp[nv][0] + dp[nv][1] + 2 * dp[nv][2]);
            }
        }
        if (C[v] == 'a') {
            dp[v][0] = x;
            dp[v][2] = y - x;
        } else {
            dp[v][1] = x;
            dp[v][2] = y - x;
        }
    };
    dfs(dfs, 0);
    cout << dp[0][2].val() << endl;
    return 0;
}