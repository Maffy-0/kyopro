#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll inf = 1e18;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int h, w, c;
    cin >> h >> w >> c;
    vector a(h, vector<ll> (w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = inf;
    for (int k = 0; k < 2; k++) {
        vector dp(h, vector<ll> (w, inf));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
                if (j) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                }
                ans = min(ans, a[i][j] + (ll) (i + j) * c + dp[i][j]);
                dp[i][j] = min(dp[i][j], a[i][j] - (ll) (i + j) * c);
            }
        }
        reverse(a.begin(), a.end());
    }
    cout << ans << endl;
    return 0;
}