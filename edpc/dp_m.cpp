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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(n + 1, vector<mint> (k + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        vector<mint> rui(k + 2);
        for (int j = 0; j <= k; j++) {
            rui[j + 1] = rui[j] + dp[i][j];
        }
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j] = rui[j + 1] - rui[max(0, j - a[i])];
        }
    }
    cout << dp[n][k].val() << endl;
    return 0;
}