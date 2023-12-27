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
    long A, M, L, R;
    cin >> A >> M >> L >> R;
    // L以上で一番最初の木
    long left = L + ((L - A + M) % M);
    cout << left << endl;
    // R以下で一番最初の木
    long right = R - ((R - A + M) % M);
    cout << right << endl;
    cout << (right - left) / M + 1 << endl;
    return 0;
}