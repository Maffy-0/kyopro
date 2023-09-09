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
    vector<ll> rui(n + 1);
    for (int i = 0; i < n; i++) {
        rui[i + 1] = rui[i] + a[i];
    }
    const ll inf = 1e18;
    vector dp(n + 1, vector<ll> (n + 1));
    vector vis(n + 1, vector<bool> (n + 1));
    auto calc = [&](auto f, int l, int r) -> ll {
        if (l == r) {
            return 0;
        }
        if (vis[l][r]) {
            return dp[l][r];
        }
        vis[l][r] = true;
        ll res = inf;
        for (int i = l; i < r; i++) {
            res = min(res, f(f, l, i) + f(f, i + 1, r) + rui[r + 1] - rui[l]);
        }
        return dp[l][r] = res;
    };
    cout << calc(calc, 0, n - 1) << endl;
    return 0;
}