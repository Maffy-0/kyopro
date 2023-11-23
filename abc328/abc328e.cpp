#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

struct Edge {
    long long u;
    long long v;
    long long cost;
};

long long N, M, K;
vector<Edge> G(30);

int main(void) {
    fast_io();
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[i] = {u, v, w};
    }
    long long ans = K;
    auto dfs = [&](auto dfs, int i, vector<int> es) -> void {
        if ((int)es.size() == N - 1) {
            dsu uf(N);
            bool ok = true;
            long long tmp = 0;
            for (auto e : es) {
                auto ed = G[e];
                if (!uf.same(ed.u, ed.v)) {
                    uf.merge(ed.u, ed.v);
                    tmp += ed.cost;
                    tmp %= K;
                } else {
                    ok = false;
                }
            }
            if (ok) ans = min(ans, tmp);
            return;
        }
        if (i == M) {
            return;
        }
        dfs(dfs, i + 1, es);
        es.push_back(i);
        dfs(dfs, i + 1, es);
    };
    dfs(dfs, 0, {});
    cout << ans << endl;
    return 0;
}