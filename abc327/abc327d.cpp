#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, A[202020], B[202020];

int main(void) {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        B[i]--;
    }
    dsu uf(2 * N);
    bool ok = true;
    for (int i = 0; i < M; i++) {
        uf.merge(A[i], B[i] + N);
        uf.merge(B[i], A[i] + N);
    }
    for (int i = 0; i < N; i++) {
        if (uf.same(i, i + N)) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}