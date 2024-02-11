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
    int N;
    long X;
    cin >> N >> X;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    int ans = 0;
    auto f = [&](auto f, int i, long p) -> void {
        if (i == N) {
            if (p == X) ans++;
            return;
        }
        for (int x : A[i]) {
            if (p > X / x) {
                continue;
            }
            f(f, i + 1, p * x);
        }
    };

    f(f, 0, 1);
    cout << ans << endl;
    return 0;
}