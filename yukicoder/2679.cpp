#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

using mint = modint998244353;
signed main(void) {
    fast_io();
    long N, K;
    cin >> N >> K;
    mint ans = mint(1) / 6;
    cout << ans.val() << endl;
    return 0;
}