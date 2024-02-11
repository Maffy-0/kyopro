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
    vector<string> c = {"ABC", "ARC", "AGC", "AHC"};
    vector<string> d;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        d.push_back(s);
    }
    for (int i = 0; i < 4; i++) {
        bool ok = false;
        for (int j = 0; j < 3; j++) {
            if (c[i] == d[j]) ok = true;
        }
        if (!ok) {
            cout << c[i] << endl;
            return 0;
        }
    }
    return 0;
}