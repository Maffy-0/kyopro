#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long N, C;
vector<long> A(202020);

long bf() {
    long res = 0;
    for (int i = 0; i < N; i++) {
        long mul = 0;
        for (int j = i; j < N; j++) {
            mul += A[i] * C - A[i];
        }
        res = max(res, mul);
    }
    return res;
}

long solve() {
    vector<long> sum(N);
    for (int i = 0; i < N; i++) sum[i] = A[i] * C;
    vector<long> dp(N + 1);
    
}

signed main(void) {
    fast_io();
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << bf() << endl;
    cout << solve() << endl;
    return 0;
}