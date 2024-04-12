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
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if (A % K == 0) cout << A / K << " ";
    }
    cout << endl;
    return 0;
}