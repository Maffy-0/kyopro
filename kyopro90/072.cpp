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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int ans = -1;
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    vector vis(H, vector<bool> (W));
    auto f = [&](auto f, int i, int j, int si, int sj, int cnt) -> void {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W || S[ni][nj] == '#') {
                continue;
            }
            if (vis[ni][nj]) {
                if (ni == si && nj == sj && cnt >= 3 && ans < cnt) {
                    ans = cnt;
                }
            } else {
                f(f, ni, nj, si, sj, cnt + 1);
            }
        }
        vis[i][j] = false;
    };
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) if (S[i][j] == '.') {
            f(f, i, j, i, j, 1);
        }
    }
    cout << ans << endl;
    return 0;
}