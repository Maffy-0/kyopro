#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector T(N, vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> T[i][j];
        }
    }

    vector<int> ans(N, -1);
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (ans[i] != -1) continue;
            if (A[T[i][j]] > 0) {
                A[T[i][j]]--;
                ans[i] = T[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
    return 0;
}