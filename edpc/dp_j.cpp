#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

double dp[303][303][303];
int c[4];

int main(void) {
    fast_io();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    for (int k = 0; k <= n; k++) {
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                int sum = i + j + k;
                if (sum == 0) {
                    continue;
                }
                dp[i][j][k] = 1.0 * n / sum;
                if (i) {
                    dp[i][j][k] += dp[i - 1][j][k] * i / sum;
                }
                if (j) {
                    dp[i][j][k] += dp[i + 1][j - 1][k] * j / sum;
                }
                if (k) {
                    dp[i][j][k] += dp[i][j + 1][k - 1] * k / sum;
                }
            }
        }
    }
    cout << fixed << setprecision(10) << dp[c[1]][c[2]][c[3]] << endl;
    return 0;
}