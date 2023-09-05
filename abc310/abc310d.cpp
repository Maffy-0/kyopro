#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, t, m;
    cin >> n >> t >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<int> c(n);
    int ans = 0;
    auto dfs = [&](auto dfs, int x, int y) -> void {
        if (x == n) {
            if (y != t) {
                return;
            }
            bool ok = true;
            for (int i = 0; i < m; i++) {
                if (c[a[i]] == c[b[i]]) {
                    ok = false;
                }
            }
            if (ok) {
                ans++;
            }
            return;
        }
        for (int i = 0; i <= y; i++) {
            c[x] = i;
            dfs(dfs, x + 1, max(y, i + 1));
        }
    };
    dfs(dfs, 0, 0);
    cout << ans << endl;
    return 0;
}