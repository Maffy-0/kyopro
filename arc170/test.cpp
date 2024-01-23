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
    vector<string> s;
    for (int i = 0; i < (1 << 4); i++) {
        string S = "";
        for (int j = 0; j < 4; j++) {
            if (i >> j & 1) {
                S += 'A';
            } else {
                S += 'B';
            }
        }
        s.push_back(S);
    }
    for (auto S : s) cout << S << endl;
    return 0;
}