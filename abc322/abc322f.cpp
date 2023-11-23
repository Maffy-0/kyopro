#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long op(long long a, long long b) {
    return a ^ b;
}
long long e() {
    return 0LL;
}

int N, Q;
string S;

int main(void) {
    fast_io();
    cin >> N >> Q >> S;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = S[i] - '0';
    }
    segtree<long long, op, e> seg(A);

    while (Q--) {
        int c, L, R;
        cin >> c >> L >> R;
        L--;
        if (c == 1) {
            
        }
    }
    return 0;
}