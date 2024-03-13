#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void solve() {
    int D;
    long A;
    cin >> D >> A;
    for (int i = 0; i < D; i++) {
        long X;
        cin >> X;
        long res = round((long double)X / A);
        cout << res << " \n"[i == D - 1];
    }
}
signed main(void) {
    fast_io();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}