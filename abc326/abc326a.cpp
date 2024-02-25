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
    cout << (abs(X - Y) <= 2 || X - Y == 3 ? "Yes\n" : "No\n");
    return 0;
}