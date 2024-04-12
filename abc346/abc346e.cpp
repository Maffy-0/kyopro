#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> T(M), A(M), X(M);
    rep(i, M) {
        cin >> T[i] >> A[i] >> X[i];
        A[i]--;
    }
    map<long, long> mp;
    vector<bool> h(H, true), w(W, true);
    long nh = H, nw = W;
    rev(i, M) {
        if (T[i] == 1) {
            if (h[A[i]]) {
                mp[X[i]] += nw;
                h[A[i]] = false;
                nh--;
            }
        } else {
            if (w[A[i]]) {
                mp[X[i]] += nh;
                w[A[i]] = false;
                nw--;
            }
        }
        if (nh == 0 || nw == 0) break;
    }
    if (nh > 0 && nw > 0) mp[0] += nh * nw;
    cout << mp.size() << '\n';
    for (auto [a, b] : mp) cout << a << " " << b << '\n';
    return 0;
}