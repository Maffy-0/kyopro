#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, Q;
    cin >> N >> Q;
    vector<long> X(N), Y(N);
    long lx, rx, ly, ry;
    for (int i = 0; i < N; i++) {
        long x, y;
        cin >> x >> y;
        X[i] = x + y;
        Y[i] = x - y;
        if (i == 0) {
            lx = rx = X[i];
            ly = ry = Y[i];
        }
        lx = min(lx, X[i]);
        ly = min(ly, Y[i]);
        rx = max(rx, X[i]);
        ry = max(ry, Y[i]);
    }
    while (Q--) {
        int i;
        cin >> i;
        i--;
        long ans = max({rx - X[i], X[i] - lx, ry - Y[i], Y[i] - ly});
        cout << ans << '\n';
    }
    return 0;
}