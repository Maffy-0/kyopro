#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long A, B, C, D, E, F;

int main(void) {
    fast_io();
    cin >> A >> B >> C >> D >> E >> F;
    mint ans = (mint)A * (mint)B * (mint)C - (mint)D * (mint)E * (mint)F;
    cout << ans.val() << endl;
    return 0;
}