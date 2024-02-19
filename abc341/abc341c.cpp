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
    int H, W, N;
    string T;
    cin >> H >> W >> N >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                continue;
            }
            bool ok = true;
            int y = i, x = j;
            for (int k = 0; k < N; k++) {
                if (T[k] == 'L') {
                    x--;
                } else if (T[k] == 'R') {
                    x++;
                } else if (T[k] == 'U') {
                    y--;
                } else {
                    y++;
                }
                if (x < 0 || x > W || y < 0 || y > H || S[y][x] == '#') {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
    }
    cout << ans << endl;
    return 0;
}