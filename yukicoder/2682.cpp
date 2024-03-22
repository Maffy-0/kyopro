#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long N, K;
    cin >> N >> K;
    vector<long> A(N);
    long l = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] = gcd(A[i], K);
        l = lcm(l, A[i]);
        // cout << A[i] << " ";
    }
    // cout << endl;
    // cout << l << endl;
    

    cout << (l % K == 0 ? "Yes\n" : "No\n");
    return 0;
}