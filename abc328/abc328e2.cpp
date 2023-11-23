#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, M, K, u, v, w, C[10][10];

int main(void) {
    fast_io();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            C[i][j] = -1;
        }
    }
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        u--, v--;
        C[u][v] = C[v][u] = w;
    }
    vector<set<long long>> dp(1 << N);
    for (int i = 0; i < N; i++) {
        dp[1 << i].insert(0);
    }
    for (int i = 0; i < (1 << N) - 1; i++) {
        for (int u = 0; u < N; u++) {
            if (!(i >> u & 1)) continue;
            for (int v = 0; v < N; v++) {
                if (i >> v & 1) continue;
                if (C[u][v] == -1) continue;
                for (long long c : dp[i]) {
                    dp[i | 1 << v].insert((c + C[u][v]) % K);
                }
            }
        }
    }
    long long ans = K;
    for (long long c : dp[(1 << N) - 1]) {
        ans = min(ans, c);
    }
    cout << ans << endl;
    return 0;
}