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
    int Y;
    cin >> Y;
    for (int i = Y; ; i++) {
        if (i % 4 == 2) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}