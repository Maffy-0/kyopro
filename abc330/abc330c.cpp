#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long D;

int main(void) {
    fast_io();
    cin >> D;
    long long ans = 1e18;
    for (long long i = 0; i * i <= D; i++) {
        // i^2 + j^2 <= D となる最大のj
        long long ok = 0, ng = 1e7;
        while (abs(ok - ng) > 1) {
            long long md = (ok + ng) / 2;
            if (i * i + md * md <= D) {
                ok = md;
            } else {
                ng = md;
            }
        }
        ans = min(ans, abs(i * i + ok * ok - D));
        ans = min(ans, i * i + (ok + 1) * (ok + 1) - D);
    }
    cout << ans << endl;
    return 0;
}