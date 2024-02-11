#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
const long INF = 1e18;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long dp[202020];

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<long> A(N), B(N), X(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i] >> X[i];
        // X[i]--;
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + A[i]);
        dp[X[i]] = min(dp[X[i]], dp[i] + B[i]);
    }
    for (int i = 0; i <= N; i++) {
        cout << dp[i] << " \n"[i == N];
    }
    cout << dp[N - 1] << endl;
    return 0;
}