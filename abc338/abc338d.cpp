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
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
        X[i]--;
    }
    vector<long> rui(N + 1);
    auto f = [&](int l, int r, long s) {
        rui[l] += s;
        rui[r] -= s;
    };
    for (int i = 0; i < M - 1; i++) {
        int a = X[i], b = X[i + 1];
        if (a > b) {
            swap(a, b);
        }
        int p = b - a, q = N - p;
        f(a, b, q);
        f(b, N, p);
        f(0, a, p);
    }
    for (int i = 0; i < N; i++) {
        rui[i + 1] += rui[i];
    }
    long ans = 1e18;
    for (int i = 0; i < N; i++) {
        ans = min(ans, rui[i]);
    }
    cout << ans << endl;
    return 0;
}