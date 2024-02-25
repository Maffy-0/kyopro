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
    long N, A, B, C;
    cin >> N >> A >> B >> C;
    vector D(N, vector<long> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }
    const long inf = 2e18;

    auto f = [&](int v, long x, long y) -> vector<long> {
        vector<long> dist(N, inf);
        dist[v] = 0;
        vector<bool> vis(N);
        for (int i = 0; i < N; i++) {
            pair<long, long> best = make_pair(inf, 0);
            for (int j = 0; j < N; j++) {
                if (!vis[j]) {
                    best = min(best, {dist[j], j});
                }
            }
            int nv = best.second;
            vis[nv] = true;
            for (int j = 0; j < N; j++) {
                dist[j] = min(dist[j], dist[nv] + D[nv][j] * x + y);
            }
        }
        return dist;
    };
    auto s = f(0, A, 0);
    auto t = f(N - 1, B, C);
    long ans = inf;
    for (int i = 0; i < N; i++) {
        ans = min(ans, s[i] + t[i]);
    }
    cout << ans << endl;
    return 0;
}