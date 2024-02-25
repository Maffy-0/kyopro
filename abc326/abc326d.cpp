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
    int N;
    string R, C;
    cin >> N >> R >> C;
    vector<string> A(N, string(N, '.'));

    auto check = [&]() {
        for (int i = 0; i < N; i++) {
            vector<bool> b(3);
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 'A') b[0] = true;
                if (A[i][j] == 'B') b[1] = true;
                if (A[i][j] == 'C') b[2] = true;
            }
            bool ok = true;
            for (int j = 0; j < 3; j++) {
                ok &= b[j];
            }
            if (!ok) {
                return false;
            }
        }
        for (int i = 0; i < N; i++) {
            vector<bool> b(3);
            for (int j = 0; j < N; j++) {
                if (A[j][i] == 'A') b[0] = true;
                if (A[j][i] == 'B') b[1] = true;
                if (A[j][i] == 'C') b[2] = true;
            }
            bool ok = true;
            for (int j = 0; j < 3; j++) {
                ok &= b[j];
            }
            if (!ok) {
                return false;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] != '.') {
                    if (A[i][j] != R[i]) {
                        return false;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[j][i] != '.') {
                    if (A[j][i] != C[i]) {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    for (int i = 0; i < 1 << N; i++) {
        
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }
    return 0;
}