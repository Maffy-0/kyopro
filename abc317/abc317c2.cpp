#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = 1e18;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector cost(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        cost[u][v] = cost[v][u] = w;
    }
    int ans = 0;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        int now = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cost[p[i]][p[i + 1]] == 0) {
                break;
            }
            now += cost[p[i]][p[i + 1]];
        }
        ans = max(ans, now);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}