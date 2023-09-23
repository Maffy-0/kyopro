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
    long long X;
    cin >> X;
    if (X >= 0) {
        cout << X / 10 << endl;
    } else {
        cout << (X + 1) / 10 - 1 << endl;
    }
    return 0;
}