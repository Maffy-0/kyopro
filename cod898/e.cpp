#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int MX = 202020;
long long Q, N, X, A[MX];

int main(void) {
    fast_io();
    cin >> Q;
    while (Q--) {
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        long long ok = 1, ng = (long long) 2e9 + 1;
        while (ng - ok > 1) {
            long long md = (ok + ng) / 2;
            long long cnt = X;
            for (int i = 0; i < N; i++) {
                if (A[i] < md) {
                    cnt -= md - A[i];
                }
                if (cnt < 0) {
                    break;
                }
            }
            if (cnt >= 0) {
                ok = md;
            } else {
                ng = md;
            }
        }
        cout << ok << '\n';
    }
    return 0;
}