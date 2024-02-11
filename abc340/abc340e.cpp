#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}


long op(long f, long x) { return f + x; }
long e(){ return 0L; }


signed main(void) {
    fast_io();
    long N, M;
    cin >> N >> M;
    vector<long> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    lazy_segtree<long, op, e, long, op, op, e> seg(A);
    for (int i = 0; i < M; i++) {
        long id = B[i];
        long val = seg.get(id);
        seg.set(id, 0L);
        seg.apply(0, N, val / N);
        val %= N;
        if (val == 0) {
            continue;
        }
        if (id + val < N) {
            seg.apply(id + 1, id + val + 1, 1L);
        } else {
            seg.apply(id + 1, N, 1L);
            seg.apply(0, id + val - N + 1, 1L);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << seg.get(i) << " \n"[i == N - 1];
    }
    return 0;
}