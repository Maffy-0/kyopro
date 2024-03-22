#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long A, B, C, D;
    cin >> A >> B >> C >> D;
    long N = A * C - B * D;
    long M = A * D + B * C;
    cout << N << " " << M << endl;
    return 0;
}