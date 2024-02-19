#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

// 最長増加部分列（LIS）を取得する
vector<long> get_LIS(const vector<long> &A) {
    vector<long> lis, res;
    for (long a : A) {
        auto it = lower_bound(lis.begin(), lis.end(), a);
        res.push_back(int(it - lis.begin()) + 1);
        if (it == lis.end()) {
            lis.push_back(a);
        } else {
            *it = a;
        }
    }
    return res;
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto L = get_LIS(A);
    reverse(A.begin(), A.end());
    auto R = get_LIS(A);
    long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, L[i] + R[N - i - 1] - 1);
    }
    cout << ans << endl;
    return 0;
}