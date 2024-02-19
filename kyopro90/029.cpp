#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}
long op(long a, long b) {
    return max(a, b);
}
long e() {
    return 0;
}
long mapping(long f, long x) {
    return f ? f : x;
}
long composition(long f, long g) {
    return f ? f : g;
}
long id() {
    return 0;
}

signed main(void) {
    fast_io();
    int W, N;
    cin >> W >> N;
    lazy_segtree<long, op, e, long, mapping, composition, id> seg(W + 2);
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        long mx = seg.prod(l, r + 1) + 1;
        seg.apply(l, r + 1, mx);
        cout << mx << "\n";
    }
    return 0;
}