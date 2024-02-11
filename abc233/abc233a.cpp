#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int X, Y;
    cin >> X >> Y;
    cout << max(0, (Y - X + 9) / 10) << endl;
    return 0;
}