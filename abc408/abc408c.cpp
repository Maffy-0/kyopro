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
    int N, M;
    cin >> N >> M;
    vector<int> L(M + 1), R(M + 1);
    rep(i, M) {
        cin >> L[i] >> R[i];
        L[i]--;
    }
    vector<int> rui(N + 1);
    rep(i, M) {
        rui[L[i]]++;
        rui[R[i]]--;
    }
    rep(i, N) {
        rui[i + 1] += rui[i];
    }
    int ans = 1e9;
    rep(i, N) ans = min(ans, rui[i]);
    cout << ans << endl;
    return 0;
}