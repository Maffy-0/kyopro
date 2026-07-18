#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long n, m;
    cin >> n >> m;
    vector<pair<long, long>> c(m);
    rep(i, m) {
        long a, b;
        cin >> a >> b;
        c[i] = {a, a - b};
    }
    sort(all(c));
    
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    long ans = 0;
    long cnt = n;
    int idx = 0;
    while (!pq.empty() || idx < m) {
        while (idx < m && c[idx].first <= cnt) {
            pq.emplace(c[idx].second, c[idx].first);
            idx++;
        }
        if (pq.empty()) break;

        auto [a, b] = pq.top();
        pq.pop();
        long take = (cnt - b) / a + 1;
        ans += take;
        cnt -= take * a;
    }
    cout << ans << endl;
    return 0;
}