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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector dp(n + 1, vector<int> (m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    string ans = "";
    int i = n, j = m;
    while (i && j) {
        if (s[i - 1] == t[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
            ans.push_back(s[i - 1]);
            i--, j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}