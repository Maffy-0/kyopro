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
    int N, M;
    cin >> N >> M;
    scc_graph G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }
    auto scc = G.scc();
    long ans = 0;
    for (auto v : scc) {
        int x = v.size();
        ans += (long) x * (x - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}