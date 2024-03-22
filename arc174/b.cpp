#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void solve() {
    int N = 5;
    vector<long> A(N), P(N);
    long ans = 0;
    long eva = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        eva += (i + 1) * A[i];
        cnt += A[i];
    }
    for (int i = 0; i < N; i++) cin >> P[i];
    if (eva >= cnt * 3) {
        cout << 0 << "\n";
        return;
    }

}
signed main(void) {
    fast_io();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}