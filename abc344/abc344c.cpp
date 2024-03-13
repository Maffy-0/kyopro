#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long A[101], B[101], C[101];

signed main(void) {
    fast_io();
    int N, M, L, Q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> C[i];
    }
    set<long> st;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < L; k++) {
                st.insert(A[i] + B[j] + C[k]);
            }
        }
    }
    cin >> Q;
    long X;
    while (Q--) {
        cin >> X;
        cout << (st.count(X) ? "Yes\n" : "No\n");
    }
    return 0;
}