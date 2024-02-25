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
    int N, M;
    cin >> N >> M;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    A.push_back(9e18);
    int ans = 1;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(A.begin(), A.end(), A[i] + M);
        int sa = it - A.begin() - i;
        ans = max(ans, sa);
    }
    cout << ans << endl;
    return 0;
}