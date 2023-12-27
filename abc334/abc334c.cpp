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
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<long> B(K - 1);
    vector<tuple<long, int, int>> p;
    for (int i = 0; i < K - 1; i++) {
        B[i] = A[i + 1] - A[i];
        p.emplace_back(B[i], A[i], A[i + 1]);
    }
    sort(p.begin(), p.end());
    vector<int> vis(N + 1);
    long ans = 0;
    for (auto [cost, i, j] : p) {
        if (vis[i] || vis[j]) continue;
        vis[i] = vis[j] = true;
        ans += cost;
    }
    cout << ans << endl;
    return 0;
}