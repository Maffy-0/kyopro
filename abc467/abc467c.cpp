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
    int n, m;
    cin >> n >> m;
    assert(m == 2);
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];

    int ans = 0;
    rep(i, n - 1) {
        if ((a[i] + a[i + 1]) % m != b[i]) {
            a[i + 1]++;
            ans++;
        }
    }
    ans = min(ans, n - ans);
    cout << ans << endl;
    return 0;
}