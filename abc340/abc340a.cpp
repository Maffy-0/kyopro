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
    int A, B, D;
    cin >> A >> B >> D;
    for (int i = A; i <= B; i += D) {
        cout << i << " \n"[i == B];
    }
    return 0;
}