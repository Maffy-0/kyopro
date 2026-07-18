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
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        
        int one = 0;
        vector<int> A(N);
        rep(i, N) {
            if (S[i] == '1') {
                one++;
                A[i] = 1;
            } else {
                A[i] = -1;
            }
        }

        int now = 0;
        int res = 0;
        rep(i, N) {
            now = max(now + A[i], A[i]);
            res = max(res, now);
        }

        int ans = one - res;
        cout << ans << '\n';        
    }
    return 0;
}