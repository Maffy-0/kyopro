#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n;
    cin >> n;
    vector d(n, vector<int> (n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    vector<ll> dp(1 << n);
    ll ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        ans = max(ans, dp[i]);
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!(i >> j & 1) && !(i >> k & 1)) {
                    int ni = i | 1 << j | 1 << k;
                    dp[ni] = max(dp[ni], dp[i] + d[j][k]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}