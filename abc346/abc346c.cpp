#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long N, K;
    cin >> N >> K;
    unordered_set<long> st;
    long ans = K * (K + 1) / 2;
    rep(i, N) {
        long A;
        cin >> A;
        if (!st.count(A) && A <= K) {
            st.insert(A);
            ans -= A;
        }
    }
    cout << ans << endl;
    return 0;
}