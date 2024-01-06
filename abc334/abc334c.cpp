#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N, K;
    cin >> N >> K;
    vector<int> A(202020);
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        A[a] = 1;
    }
    vector<int> B;
    for (int i = 1; i <= N; i++) {
        for (int j = A[i]; j < 2; j++) {
            B.push_back(i);
        }
    }
    int M = B.size();
    if (M % 2 == 0) {
        long ans = 0;
        for (int i = 0; i < M; i += 2) {
            ans += B[i + 1] - B[i];
        }
        cout << ans << endl;
        return 0;
    }
    vector<long> L(M + 1), R(M + 1);
    for (int i = 0; i < M; i += 2) {
        L[i + 2] = L[i] + B[i + 1] - B[i];
    }
    for (int i = M - 2; i >= 0; i -= 2) {
        R[i] = R[i + 2] + B[i + 1] - B[i];
    }
    long ans = 2e18;
    for (int i = 0; i < M; i++) {
        if (i % 2 == 0) {
            ans = min(ans, L[i] + R[i + 1]);
        } else {
            ans = min(ans, L[i - 1] + B[i + 1] - B[i - 1] + R[i + 2]);
        }
    }
    cout << ans << endl;
    return 0;
}