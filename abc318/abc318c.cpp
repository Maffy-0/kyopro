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
    int n, d, p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        ans += f[i];
    }
    sort(f.rbegin(), f.rend());
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + f[i];
    }   
    for (int i = d; i <= n; i += d) {
        ll cur = s[i] - s[i - d];
        if (cur > p) {
            ans = ans - cur + p;
        } else {
            break;
        }
    }
    if (n % d != 0) {
        ll idx = (n / d) * d;
        ll cur = s[n] - s[idx];
        if (cur > p) {
            ans = ans - cur + p;
        }
    }
    cout << ans << endl;
    return 0;
}