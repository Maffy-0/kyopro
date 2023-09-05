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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (i * n <= m) {
                ans = max(ans, i);
            }
            if (i >= n) {
                ans = max(ans, m / i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}