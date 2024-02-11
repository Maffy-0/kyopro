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
    int H, W;
    cin >> H >> W;
    vector P(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> P[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << H; i++) {
        int cnt = __builtin_popcount(i);
        map<int, int> mp;
        for (int j = 0; j < W; j++) {
            int pre = -1;
            bool ok = true;
            for (int k = 0; k < H; k++) if (i >> k & 1) {
                if (pre == -1 || pre == P[k][j]) {
                    pre = P[k][j];
                } else {
                    ok = false;
                }
            }
            if (ok) {
                mp[pre]++;
            }
        }
        for (auto [_, c] : mp) {
            ans = max(ans, c * cnt);
        }
    }
    cout << ans << endl;
    return 0;

}