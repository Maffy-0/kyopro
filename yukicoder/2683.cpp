#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

mint f(int H, int A) {
    mint res;
    for (int i = 0; i < H; i++) {
        int L = max(0, i - A + 1);
        int R = min(i, H - A);
        mint add = mint(R - L + 1) / (H - A + 1);
        add *= add;
        res += add;
    }
    return res;
}

signed main(void) {
    fast_io();
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    mint ans = mint(2) * A * B;
    ans -= f(H, A) * f(W, B);
    cout << ans.val() << endl;
    return 0;
}