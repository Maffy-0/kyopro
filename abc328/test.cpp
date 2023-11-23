#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    for (int i = 0; i < 202020; i++) {
        if (i % 3 == 0) {
            cout << 'A';
        } else if (i % 3 == 1) {
            cout << 'A';
        } else {
            cout << 'C';
        }
    }
    cout << endl;
    return 0;
}