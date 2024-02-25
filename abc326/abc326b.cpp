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
    for (int i = N; ; i++) {
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;
        if (a * b == c) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}