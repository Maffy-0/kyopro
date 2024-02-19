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
    return -1;
}
signed main(void) {
    fast_io();
    long W, N;
    cin >> W >> N;
    segtree<long, op, e> seg(W + 1);
    seg.set(0, 0);
    for (long i = 0; i < N; i++) {
        long l, r, v;
        cin >> l >> r >> v;
        for (long j = W; j >= 0; j--) {
            long L = max(0L, j - r);
            long R = max(0L, j - l + 1);
            long x = seg.prod(L, R);
            if (x >= 0) {
                seg.set(j, max(seg.get(j), x + v));
            }
        }        
    }
    cout << seg.get(W) << endl;
    return 0;
}