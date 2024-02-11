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
    long K;
    cin >> K;
    long ans = 0;
    for (long i = 1; i <= 10000; i++) {
        if (K % i) {
            continue;
        }
        long jk = K / i;
        if (jk < i) {
            continue;
        }
        long sq = sqrt(jk);
        for (int j = 1; j <= sq; j++) {
            if (jk % j) {
                continue;
            }
            long k = K / j;
            if (i <= j && j <= k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}