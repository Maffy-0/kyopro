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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int ans = 1e9;

    for (int i = 0; i < H; i++) {
        int cnt = 0;
        int sousa = 0;
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'o') {
                cnt++;
            } else if (S[i][j] == '.') {
                cnt++;
                sousa++;
            } else {
                cnt = 0;
                sousa = 0;
            }
            if (cnt == K) {
                ans = min(ans, sousa);
                cnt--;
                sousa -= (S[i][j - K + 1] == '.');
            }
        }
    }

    for (int i = 0; i < W; i++) {
        int cnt = 0;
        int sousa = 0;
        for (int j = 0; j < H; j++) {
            if (S[j][i] == 'o') {
                cnt++;
            } else if (S[j][i] == '.') {
                cnt++;
                sousa++;
            } else {
                cnt = 0;
                sousa = 0;
            }
            if (cnt == K) {
                ans = min(ans, sousa);
                cnt--;
                sousa -= (S[j - K + 1][i] == '.');
            }
        }
    }

    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl; 
    return 0;
}