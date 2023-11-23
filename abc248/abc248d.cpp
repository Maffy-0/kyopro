#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, Q;
vector<int> A[202020];

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        A[a].push_back(i);
    }
    cin >> Q;
    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;
        auto res = upper_bound(A[x].begin(), A[x].end(), r) - lower_bound(A[x].begin(), A[x].end(), l);
        cout << res << '\n';
    }
    return 0;
}