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
    string T = "";
    for (int i = 0; i < 100; i++) {
        T.push_back('a');
    }
    cout << T << endl;
    cout << 100 << endl;
    for (int i = 0; i < 100; i++) {
        cout << 10 << " ";
        for (int j = 0; j < 10; j++) {
            char c = 'a' + j;
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}