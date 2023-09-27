#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int MX = 3030;
int H, W, N;
int dp[MX][MX], h[MX][MX];

int main(void) {
    fast_io();
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        h[a][b] = 1;
    }

    long long ans = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (h[i][j] == 1) {
                continue;
            }
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            ans += (long long) dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}