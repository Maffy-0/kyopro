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
    long N, L, R;
    cin >> N >> L >> R;
    vector<long> A(N);
    long ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ans += A[i];
    }
    
    return 0;
}