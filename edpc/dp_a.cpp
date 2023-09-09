#include <atcoder/all>
#include <bits/stdc++.h>
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
    vector<ll> h(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    vector<ll> dp(n + 1, 1e9);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i >= 3) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n] << endl;
    return 0;
}