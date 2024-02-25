#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long N;
    cin >> N;
    vector<long> A(202020);
    for (int i = 0; i < N; i++) {
        long a;
        cin >> a;
        for (long j = 2; j * j <= a; j++) {
            while (a % (j * j) == 0) a /= j * j;
        }
        A[a]++;
    }
    long ans = (N - A[0]) * A[0];
    for (int i = 0; i <= 200000; i++) {
        ans += A[i] * (A[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}