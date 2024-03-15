#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    dsu uf(N);
    for (int i = 0; i < N - 1; i++) {
        if (A[i] == A[i + 1] || A[i] + 1 == A[i + 1]) {
            uf.merge(i, i + 1);
        }
    }
    if (((A.back() + 1) % M == 0) && A[0] == 0) uf.merge(0, N - 1);

    auto g = uf.groups();
    long ans = sum;
    for (vector<int> v : g) {
        long cnt = 0;
        for (int u : v) {
            cnt += A[u];
        }
        ans = min(ans, sum - cnt);
    }
    cout << ans << endl;
    return 0;
}