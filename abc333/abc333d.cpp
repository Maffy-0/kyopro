#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N;
    cin >> N;
    dsu uf(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u != 0 && v != 0) {
            uf.merge(u, v);
        }
    }
    int mx = 0;
    for (int i = 1; i < N; i++) {
        mx = max(mx, uf.size(i));
    }
    cout << N - mx << endl;
    return 0;
}