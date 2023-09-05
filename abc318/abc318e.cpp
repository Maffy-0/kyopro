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
        a[i]--;
    }

    vector<int> cnt(n);
    vector<ll> isum(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (ll) (i - 1) * cnt[a[i]] - isum[a[i]];
        cnt[a[i]]++;
        isum[a[i]] += i;
    }
    auto nc3 = [&](ll x) -> ll {
        return x * (x - 1) * (x - 2) / 6;
    }; 
    for (int i = 0; i < n; i++) {
        ans -= nc3(cnt[i]);
    }
    cout << ans << endl;
    return 0;
}