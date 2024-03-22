#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, K;
    cin >> N >> K;
    int M;
    cin >> M;
    vector<int> S(N + 1, 2);
    for (int i = 0; i < M; i++) {
        int A;
        cin >> A;
        S[A] = 1;
    }
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int B;
        cin >> B;
        S[B] = 0;
    }
    for (int i = 1; i <= N; i++) {
        S[i] = min(S[i], S[i - 1]);
        if (i - K >= 0) S[i] = min(S[i], S[i - K]);
    }
    cout << S[N] << endl;
    return 0;
}