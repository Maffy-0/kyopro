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
    int N;
    cin >> N;
    vector<long> Q(N), A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    long ans = 0;

    // Aが何個作れるか
    for (int i = 0; i <= 1e6; i++) {
        long res = 1e9;
        bool flag = true;
        for (int j = 0; j < N; j++) {
            long left = Q[j] - i * A[j];
            if (left < 0) {
                flag = false;
                break;
            }
            long ok = 0, ng = 1e6 + 1;
            while (ng - ok > 1) {
                long md = (ok + ng) / 2;
                if (left >= md * B[j]) {
                    ok = md;
                } else {
                    ng = md;
                }
            }
            res = min(res, i + ok);
        }
        if (res == 1e9 || !flag) {
            continue;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}