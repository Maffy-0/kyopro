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
    long long N, M, P;
    cin >> N >> M >> P;
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i] + B[j] < P) {
                ans += A[i] + B[j];
            } else {
                ans += P;
            }
        }
    }
    cout << ans << endl;
    return 0;
}