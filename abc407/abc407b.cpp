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
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    rep(i, 7) {
        rep(j, 7) {
            if (i == 0 || j == 0) continue;
            if (i + j < x && abs(i - j) < y) {
                cnt++;
            }
        }
    }
    cout << setprecision(16) << fixed;
    cout << 1 - double(cnt) / 36.0 << endl;
    return 0;
}