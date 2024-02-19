#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int dp[101][101010];

signed main(void) {
    fast_io();
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101010; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j + A[i] <= S) {
                chmax(dp[i + 1][j + A[i]], dp[i][j]);
            }
            if (j + B[i] <= S) {
                chmax(dp[i + 1][j + B[i]], dp[i][j]);
            }
        }
    }
    if (dp[N][S] == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int v = S;
    string ans = "";
    for (int i = N - 1; i >= 0; i--) {
        if (v - A[i] >= 0 && dp[i][v - A[i]] == 1) {
            ans = 'A' + ans;
            v -= A[i];
        } else if (v - B[i] >= 0 && dp[i][v - B[i]] == 1) {
            ans = 'B' + ans;
            v -= B[i];
        } else {
            // cout << "i : " << i << ", ans : " << ans << endl;
            return 1;
        }
    }
    cout << ans << endl;
    return 0;
}