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
    int Q;
    cin >> Q;
    vector<int> v;
    while (Q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            v.push_back(x);
        } else {
            cout << v[v.size() - x] << '\n';
        }
    }
    return 0;
}