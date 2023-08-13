#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

// dp
int h, w;
int a[2020][2020];
vector dp(2020, vector<int> (2020, -1e9));

int main(void) {
    fast_io();
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = s[i][j] == '+' ? 1 : -1;
        }
    }
    dp[h - 1][w - 1] = 0;
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (i < h - 1) {
                dp[i][j] = max(dp[i][j], a[i + 1][j] - dp[i + 1][j]);
            }
            if (j < w - 1) {
                dp[i][j] = max(dp[i][j], a[i][j + 1] - dp[i][j + 1]);
            }
        }
    }
    int score = dp[0][0];
    if (score == 0) {
        cout << "Draw\n";
    } else if (score < 0) {
        cout << "Aoki\n";
    } else {
        cout << "Takahashi\n";
    }
    return 0;
}