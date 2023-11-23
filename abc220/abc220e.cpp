#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, D;

int main(void) {
    fast_io();
    cin >> N >> D;
    
    long long root = 1, ans = 0;
    bool ok = false;
    while (1) {
        long long l = root, r = root;
        for (int i = 0; i < D; i++) {
            l *= 2;
            r = r * 2 + 1;
            if (l > N) {
                ok = true;
            }
        }
        r = min(r, N);
        ans += root * (r - l + 1);
        if (ok) {
            break;
        }
        root *= 2;
    }
    cout << ans << endl;
    return 0;
}