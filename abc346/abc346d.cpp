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

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

signed main(void) {
    fast_io();
    long N;
    cin >> N;
    string S;
    cin >> S;
    vector<long> C(N);
    rep(i, N) cin >> C[i];
    vector L(N + 1, vector<long> (2));
    auto R = L;
    rep(i, N) {
        L[i + 1][0] = L[i][1];
        L[i + 1][1] = L[i][0];
        L[i + 1]['1' - S[i]] += C[i];
    }
    rev(i, N) {
        R[i][0] = R[i + 1][1];
        R[i][1] = R[i + 1][0];
        R[i]['1' - S[i]] += C[i];
    }
    long ans = 2e18;
    rep(i, N - 1) {
        chmin(ans, L[i + 1][0] + R[i + 1][0]);
        chmin(ans, L[i + 1][1] + R[i + 1][1]);
    }
    cout << ans << endl;
    return 0;
}