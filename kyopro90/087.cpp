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
    long N, P, K;
    cin >> N >> P >> K;
    vector A(N, vector<long> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    auto g = [&](long x) -> long {
        vector B(N, vector<long> (N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = (A[i][j] == -1 ? x : A[i][j]);
            }
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
                }
            }
        }
        long res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (B[i][j] <= P) {
                    res++;
                }
            }
        }
        return res;
    };
    auto f = [&](long x) -> long {
        long L = 0, R = P + 2;
        while (R - L > 1) {
            long md = (L + R) / 2;
            if (g(md) >= x) {
                L = md;
            } else {
                R = md;
            }
        }
        return L;
    };
    long R = f(K);
    long L = f(K + 1);
    if (L <= P && P < R) {
        cout << "Infinity\n";
    } else {
        cout << R - L << endl;
    }
    return 0;
}