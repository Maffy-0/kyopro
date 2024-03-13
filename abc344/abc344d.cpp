#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

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
    string T;
    int N;
    cin >> T >> N;
    vector<vector<string>> S(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        for (int j = 0; j < A; j++) {
            string s;
            cin >> s;
            S[i].push_back(s);
        }
    }

    // dp[i][j] : i 袋目までみて T の j 文字目までつくるときの最小コスト
    int ts = T.size();
    vector dp(N + 1, vector<int>(ts + 1, 1e9));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= ts; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        for (int j = 0; j <= ts; j++) {
            for (string s : S[i]) {
                int l = s.size();
                if (j + l > ts) continue;
                bool ok = true;
                for (int k = 0; k < l; k++) {
                    ok &= s[k] == T[k + j];
                }
                if (ok) {
                    chmin(dp[i + 1][j + l], dp[i][j] + 1);
                }
            }
        }
    }
    int ans = dp[N][ts];
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}