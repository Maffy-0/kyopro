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
    int n;
    cin >> n;
    vector a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<mint> dp(1 << n);
    dp[0] = 1;
    for (int i = 0; i < 1 << n; i++) {
        int cnt = __builtin_popcount(i) - 1;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                if (a[cnt][j] == 1) {
                    dp[i] += dp[i - (1 << j)];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].val() << endl;
    return 0;
}