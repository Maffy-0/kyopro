#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector dp(h, vector<mint> (w));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                continue;
            }
            if (i) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[h - 1][w - 1].val() << endl;
    return 0;
}