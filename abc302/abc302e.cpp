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
    int n, q;
    cin >> n >> q;

    vector<set<int>> e(n);
    int ans = n;
    for (int i = 0; i < q; i++) {
        int ope;
        cin >> ope;
        if (ope == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (e[u].empty()) {
                ans--;
            }
            if (e[v].empty()) {
                ans--;
            }
            e[u].insert(v);
            e[v].insert(u);
        } else {
            int u;
            cin >> u;
            u--;
            if (!e[u].empty()) {
                ans++;
                for (int v : e[u]) {
                    e[v].erase(u);
                    if (e[v].empty()) {
                        ans++;
                    }
                }
                e[u].clear();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}