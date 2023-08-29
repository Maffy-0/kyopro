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
    ll n;
    cin >> n;
    // 高橋君が必要な議席
    ll need = 0;
    // 今高橋君が持っている議席
    ll now = 0;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        need += c;
        if (a > b) {
            now += c;
        } else {
            ll half = (a + b + 1) / 2;
            v.push_back({half - a, c});
        }
    }
    need = (need + 1) / 2;
    if (need <= now) {
        cout << 0 << endl;
        return 0;
    }
    auto comp = [&](pair<ll, ll> p, pair<ll, ll> q) {
        return p.first * q.second < p.second * q.first;
    };
    sort(v.begin(), v.end(), comp);
    int m = v.size();
    ll ans = 0;
    vector<vector<ll>> dp(m + 1, vector<ll> (2, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < m; i++) {
        dp[i + 1][1] = dp[i][0] + v[i].
    }

    return 0;
}