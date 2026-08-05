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

void solve() {
    long px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

    long pqx = px - qx;
    long pqy = py - qy;
    long rsx = rx - sx;
    long rsy = ry - sy;

    // pq, rsが交わる場合絶対ある
    long a = pqx * rsy - pqy * rsx;
    if (a != 0) {
        YesNo(true);
        return;
    }

    // pq, rsが平行な場合，一致してればある
    long midx = px + qx - rx - sx;
    long midy = py + qy - ry - sy;
    YesNo(pqx * midx + pqy * midy == 0);
}

signed main(void) {
    fast_io();
    int t;
    cin >> t;
    rep(i, t) {
        solve();
    }
    return 0;
}