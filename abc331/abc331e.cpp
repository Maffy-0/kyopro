#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, L;
set<pair<int, int>> st;

int main(void) {
    fast_io();
    cin >> N >> M >> L;
    vector<long> A(N), B(M), C(L), D(L);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < L; i++) {
        cin >> C[i] >> D[i];
        st.emplace(A[C[i] - 1], B[D[i] - 1]);
    }
    sort(B.begin(), B.end());
    auto comp = [&] (int i) -> long {
        for (int j = M - 1; j >= 0; j--) {
            if (st.count({A[i], B[j]})) {
                continue;
            } 
            return B[j];
        }
        return -1e18;
    };
    long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, A[i] + comp(i));
    }
    cout << ans << endl;
    return 0;
}