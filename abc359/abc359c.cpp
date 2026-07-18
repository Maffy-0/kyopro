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
    long sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if ((sx + sy) % 2 == 1) sx--;
    if ((tx + ty) % 2 == 1) tx--;
    long ans = max(abs(sy - ty), (abs(sx - tx) + abs(sy - ty)) / 2);
    cout << ans << endl;
    return 0;
}