#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

struct Edge {
    int to, b, c;
};

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N, M, u, v, b, c;
vector<Edge> G[202020];

int main(void) {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> b >> c;
        u--, v--;
        G[u].push_back({v, b, c});
    }

    auto f = [&] (double x) -> bool {
        const double inf = 1e18;
        vector<double> dp(N, -inf);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (auto e : G[i]) {
                chmax(dp[e.to], dp[i] + e.b - x * e.c);
            }
        }
        return dp[N - 1] >= 0;
    };

    double ok = 0, ng = 1e6;
    for (int p = 0; p < 100; p++) {
        double md = (ok + ng) / 2;
        if (f(md)) {
            ok = md;
        } else {
            ng = md;
        }
    }

    cout << fixed <<  setprecision(10) << ok << endl;
    return 0;
}