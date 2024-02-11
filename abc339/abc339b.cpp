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
    int H, W, N;
    cin >> H >> W >> N;
    int i = 0, j = 0;
    vector<vector<char>> G(H, vector<char>(W, '.'));
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    int dr = 0;
    while (N--) {
        if (G[i][j] == '.') {
            G[i][j] = '#';
            dr = (dr + 1) % 4;
        } else {
            G[i][j] = '.';
            dr = (dr - 1 + 4) % 4;
        }
        i = (i + di[dr] + H) % H;
        j = (j + dj[dr] + W) % W;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << G[i][j];
        }
        cout << '\n';
    }
    return 0;
}