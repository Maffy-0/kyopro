#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, Q;
string S;
int sum[303030], rui[303030];

int main(void) {
    fast_io();
    cin >> N >> Q >> S;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i + 1]) {
            sum[i + 1] += 1;
        }
    }
    for (int i = 0; i < 303002; i++) {
        rui[i + 1] = rui[i] + sum[i];
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << rui[r] - rui[l] << '\n';
    }
    return 0;
}