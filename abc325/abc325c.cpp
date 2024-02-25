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
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int di[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int ans = 0;
    auto dfs = [&](auto f, int i, int j) -> void {
        S[i][j] = '*';
        for (int k = 0; k < 8; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W || S[ni][nj] != '#') {
                continue;
            }
            f(f, ni, nj);
        }
    };
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                ans++;
                dfs(dfs, i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}