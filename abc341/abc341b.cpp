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
    cin >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        long s, t;
        cin >> s >> t;
        A[i + 1] += A[i] / s * t;
    }
    // for (int i = 0; i < N; i++) cout << A[i] << " \n"[i == N - 1];
    cout << A[N - 1] << endl;
    return 0;
}