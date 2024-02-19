#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string ill = "Ambiguous";

signed main(void) {
    fast_io();
    int N, Q;
    cin >> N >> Q;
    dsu uf(N);
    fenwick_tree<long> bit(N + 1);
    while (Q--) {
        int t, x, y, v;
        cin >> t >> x >> y >> v;
        x--, y--;
        if (t == 0) {
            assert(x + 1 == y);
            if (!uf.same(x, y)) {
                uf.merge(x, y);
                if (x & 1) {
                    bit.add(x, v);
                } else {
                    bit.add(x, -v);
                }
            }
        } else {
            if (uf.same(x, y)) {
                long res = bit.sum(min(x, y), max(x, y));
                if (x & 1) v *= -1;
                if (x > y) res *= -1;
                if (y & 1) res *= -1, v *= -1;
                cout << res + v << '\n';
            } else {
                cout << ill << '\n';
            }
        }
    }
    return 0;
}