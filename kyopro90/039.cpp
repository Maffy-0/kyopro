#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    long ans = 0;
    vector<long> dp(N);
    auto f = [&](auto f, int v, int p) -> void {
        dp[v] = 1;
        for (auto nv : G[v]) if (nv != p) {
            f(f, nv, v);
            dp[v] += dp[nv];            
        }
    };
    f(f, 0, -1);
    for (int i = 0; i < N; i++) {
        ans += dp[i] * (N - dp[i]);
    }
    cout << ans << endl;
    return 0;
}