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
    int n;
    cin >> n;
    vector<tuple<int, int, int>> g(n - 1);
    for (auto &[w, u, v] : g) {
        cin >> u >> v >> w;
        u--, v--;
    }
    sort(g.begin(), g.end());
    dsu uf(n);
    ll ans = 0;
    for (auto &[w, u, v] : g) {
        ans += (ll) w * uf.size(u) * uf.size(v);
        uf.merge(u, v);
    }
    cout << ans << endl;
    return 0;
}