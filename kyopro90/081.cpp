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
    long N, K;
    cin >> N >> K;
    int M = 5050;
    vector S(M, vector<long> (M));
    auto rui = S;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        S[A][B]++;
    }
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            rui[i + 1][j + 1] += rui[i][j + 1] + rui[i + 1][j] - rui[i][j] + S[i][j];
        }
    }
    long ans = 0;
    for (int i = 0; i < M - K - 1; i++) {
        for (int j = 0; j < M - K - 1; j++) {
            ans = max(ans, rui[i + K + 1][j + K + 1] - rui[i + K + 1][j] - rui[i][j + K + 1] + rui[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}