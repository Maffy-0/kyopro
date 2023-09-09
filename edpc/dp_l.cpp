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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(n + 1, vector<ll> (n + 1));
    vector vis(n + 1, vector<ll> (n + 1));
    auto calc = [&](auto f, int l, int r) -> ll {
        if (l > r) {
            return 0;
        }
        if (vis[l][r]) {
            return dp[l][r];
        }
        vis[l][r] = true;
        int diff = n - (r - l + 1);
        ll res = 0;
        if (diff % 2 == 0) {
            res = -1e18;
            res = max(res, f(f, l + 1, r) + a[l]);
            res = max(res, f(f, l, r - 1) + a[r]);
        } else {
            res = 1e18;
            res = min(res, f(f, l + 1, r) - a[l]);
            res = min(res, f(f, l, r - 1) - a[r]);
        }
        return dp[l][r] = res;
    };
    cout << calc(calc, 0, n - 1) << endl;
    return 0;
}