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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ok = 2e9 + 1, ng = 0;
    while (ok - ng > 1) {
        ll md = (ok + ng) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= md) {
                cnt += a[i] - md + 1;
            }
        }
        if (cnt < k) {
            ok = md;
        } else {
            ng = md;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= ok) {
            ans += (a[i] - ok + 1) * (a[i] + ok) / 2;
            k -= a[i] - ok + 1;
        }
    }
    ans += k * (ok - 1);
    cout << ans << endl;
    return 0;
}