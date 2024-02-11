#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    string S = "REFGJLZXVB";
    for (char c : S) {
        for (char d : S) {
            for (char e : S) {
                if (c != 'R' && d != 'R' && e != 'R') continue;
                if (c == 'R') continue;
                if (d == 'E') continue;
                if (e == 'E') continue;
                if (e == 'R') continue;
                cout << c << 'E' << d << e << "E\n";
            }
        }
    }
    return 0;
}