#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

using mint = modint1000000007;

signed main(void) {
    fast_io();
    int N, Q;
    cin >> N >> Q;
    vector<long> X(Q), Y(Q), Z(Q), W(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--, Y[i]--, Z[i]--;
    }
    mint ans = mint(1);
    for (int bit = 0; bit < 60; bit++) {
        int cnt = 0;
        for (int i = 0; i < 1 << N; i++) {
            bool ok = true;
            for (int j = 0; j < Q; j++) {
                int x = i >> X[j] & 1;
                int y = i >> Y[j] & 1;
                int z = i >> Z[j] & 1;
                int w = W[j] >> bit & 1;
                if ((x | y | z) != w) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cnt++;
            }
        }
        ans *= cnt;
    }
    cout << ans.val() << endl;
    return 0;
}