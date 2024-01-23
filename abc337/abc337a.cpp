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
    int N;
    cin >> N;
    int t = 0, a = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        t += x;
        a += y;
    }
    if (t == a) {
        cout << "Draw" << endl;
    } else if (t < a) {
        cout << "Aoki" << endl;
    } else {
        cout << "Takahashi" << endl;
    }
    return 0;
}