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
    vector<ll> l(n);
    ll mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        mx = max(mx, l[i]);
        sum += l[i];
    }

    auto f = [&](ll x) -> bool {
        ll cnt = 1, cur = l[0];
        for (int i = 1; i < n; i++) {
            if (cur + l[i] + 1 <= x) {
                cur += l[i] + 1;
            } else {
                cnt++;
                cur = l[i];
            }
        }
        return cnt <= m;
    };
    ll ok = sum + n - 1, ng = mx - 1;
    while (ok - ng > 1) {
        ll md = (ok + ng) / 2;
        if (f(md)) {
            ok = md;
        } else {
            ng = md;
        }
    }
    cout << ok << endl;
    return 0;
}