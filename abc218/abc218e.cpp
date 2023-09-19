#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    vector<array<ll, 3>> D(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--, B[i]--;
        D[i] = {C[i], A[i], B[i]};
    }
    sort(D.begin(), D.end());
    ll ans = 0;
    dsu uf(N);
    for (int i = 0; i < M; i++) {
        auto [c, a, b] = D[i];
        if (c < 0 || !uf.same(a, b)) {
            uf.merge(a, b);
        } else {
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}