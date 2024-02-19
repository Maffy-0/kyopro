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
    cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
    long double ans = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long x = 0, y = 0;
            for (int k = L[i]; k <= R[i]; k++) {
                for (int l = L[j]; l <= R[j]; l++) {
                    if (k > l) {
                        x++;
                    }
                    y++;
                }
            }
            ans += (long double) (x) / y;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}